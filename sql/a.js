import express from "express";
const router = express.Router();
import { query } from "./db.js";

// Helper Function to convert SQL query results to JSON
const format = (res) =>
    res.values.map(row =>
      Object.fromEntries(row.map((v, i) => [res.columns[i], v]))
    );


// === 1. Fetch ALL raw logs (base dataset) ===
router.get("/all-logs", async (req, res) => {
    // TODO: Select all rows from Logs table sorted by timestamp
    const sql = `
        select
        *
        from Logs
        order by timestamp
    `;
    const result = await query(sql);
    res.json(format(result));
});


// === 2. Top Source IPs by number of requests ===
router.get("/top-ips", async (req, res) => {
    // TODO: Group by source_ip and return top 5 by hit count
    const sql = `
        select
            source_ip,
            count(*) as hit_count
        from Logs
        group by source_ip
        order by hit_count desc
        limit 5
    `;
    const result = await query(sql);
    res.json(format(result));
});


// === 3. Most Accessed API Endpoints ===
router.get("/endpoints", async (req, res) => {
    const sql = `
        select
            endpoint,
            count(*) as total_hits
        from Logs
        group by endpoint
        order by total_hits desc
        limit 5
    `;
  
    const result = await query(sql);
    const rows = format(result);
  
    const data = rows.map(r => ({
      endpoint: r.endpoint,
      total_hits: Number(
        r.total_hits ?? r.hits ?? r.count ?? r["count(*)"]
      ),
    }));
  
    res.json(data);
  });
  


// === 4. Suspicious IPs with multiple failed logins (401) ===
router.get("/failed-logins", async (req, res) => {
    // TODO: Select IPs with more than 2 failed login attempts
    const sql = `
        select
            source_ip,
            count(*) as failed_attempts
        from Logs
        where status_code = 401
        group by source_ip
        having count(*) > 2
    `;
    const result = await query(sql);
    res.json(format(result));
});


// === 5. Endpoints causing most server errors (500) ===
router.get("/server-errors", async (req, res) => {
    const sql = `
        select
            endpoint,
            count(*) as errors
        from Logs
        where status_code = 500
        group by endpoint
        order by errors desc
    `;
  
    const result = await query(sql);
    const rows = format(result);
  
    // ensure numeric errors field
    const data = rows.map(r => ({
      endpoint: r.endpoint,
      errors: Number(r.errors),
    }));
  
    res.json(data);
  });
  


// === 6. HTTP Method usage stats (GET/POST/PUT) ===
router.get("/methods-usage", async (req, res) => {
    // TODO: Count how many times each HTTP method is used
    const sql = `
        select
            method,
            count(*) as usage_count
        from Logs
        group by method
        order by usage_count desc
    `;
    const result = await query(sql);
    res.json(format(result));
});


export default router;