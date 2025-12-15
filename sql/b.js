import express from "express";
import { query } from "./db.js";
const router = express.Router();

// Helper function to convert SQL.js result into clean JSON
const format = (res) =>
  res.values.map((row) =>
    Object.fromEntries(row.map((v, i) => [res.columns[i], v]))
  );

/* 1. Fetch ALL outbreak records (recent first) */
router.get("/all", async (req, res) => {
  const sql = `
    select
      o.outbreak_id,
      c.name as country,
      o.disease,
      o.cases,
      o.deaths,
      o.report_date
    from Outbreaks o
    join Country c on c.country_id = o.country_id
    order by o.report_date desc
  `;
  const result = await query(sql);
  res.json(format(result));
});



/* 2. Country-wise totals (total cases + total deaths) */
router.get("/country-summary", async (req, res) => {
  const sql = `
    select
      c.name as country,
      sum(o.cases)  as total_cases,
      sum(o.deaths) as total_deaths
    from Outbreaks o
    join Country c on c.country_id = o.country_id
    group by c.name
    order by total_cases desc
  `;
  const result = await query(sql);
  res.json(format(result));
});



/* 3. Total cases & deaths grouped by disease */
router.get("/total-by-disease", async (req, res) => {
  const sql = `
    select
      disease,
      sum(cases)  as total_cases,
      sum(deaths) as total_deaths
    from Outbreaks
    group by disease
    order by total_cases desc
  `;
  const result = await query(sql);
  res.json(format(result));
});



/* 4. Severity Ranking — recent 14-day cases per country */
router.get("/severity-ranking", async (req, res) => {
  const sql = `
    with max_date as (
      select max(report_date) as max_report_date from Outbreaks
    )
    select
      c.name as country,
      sum(o.cases) as recent_cases
    from Outbreaks o
    join Country c on c.country_id = o.country_id
    join max_date m on 1 = 1
    where o.report_date >= date(m.max_report_date, '-14 day')
    group by c.name
    order by recent_cases desc
  `;
  const result = await query(sql);
  res.json(format(result));
});



/* 5. Trends — cumulative cases & deaths over time */
router.get("/trends", async (req, res) => {
  const { country_id } = req.query; // or req.params, depending on spec

  const sql = `
    select
      report_date,
      sum(cases) over (
        partition by country_id
        order by report_date
        rows between unbounded preceding and current row
      ) as cumulative_cases,
      sum(deaths) over (
        partition by country_id
        order by report_date
        rows between unbounded preceding and current row
      ) as cumulative_deaths
    from Outbreaks
    where country_id = ${country_id}
    order by report_date asc
  `;
  const result = await query(sql);
  res.json(format(result));
});



/* 6. Rolling 7-day mortality window
    (Uses PARTITION BY + ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) */
router.get("/mortality-window", async (req, res) => {
  const sql = `
    select
      c.name as country,
      o.report_date,
      sum(o.cases) over (
        partition by c.name
        order by o.report_date
        rows between 6 preceding and current row
      ) as rolling_cases,
      sum(o.deaths) over (
        partition by c.name
        order by o.report_date
        rows between 6 preceding and current row
      ) as rolling_deaths,
      round(
        case
          when sum(o.cases) over (
            partition by c.name
            order by o.report_date
            rows between 6 preceding and current row
          ) = 0
          then 0
          else
            1.0 * sum(o.deaths) over (
              partition by c.name
              order by o.report_date
              rows between 6 preceding and current row
            )
            / sum(o.cases) over (
              partition by c.name
              order by o.report_date
              rows between 6 preceding and current row
            )
        end,
        4
      ) as rolling_mortality
    from Outbreaks o
    join Country c on c.country_id = o.country_id
    order by c.name, o.report_date;
  `;
  const result = await query(sql);
  res.json(format(result));
});



export default router;