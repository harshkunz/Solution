
-- Write your query here
with table_1 as (
    select
        sum(p.price * s.quantity) as product_total
    from Products p 
    join Sales s 
        on p.product_id = s.product_id
        group by p.category
)

select 
    p.category,
    sum(p.price * s.quantity) as total_revenue
from Products p
join Sales s 
    on p.product_id = s.product_id
    group by p.category
having sum(p.price * s.quantity) > (select avg(product_total) from table_1)


-- Write your query here
with table_1 as (
    select 
        salary 
    from (
        select
            salary,
            row_number() over (order by salary) as rn,
            count(*) over () as c
        from Employees
    )
    where rn in ((c+1)/2, (c+2)/2)
)

select 
    * 
from Employees
where department in ('Engineering', 'Finance', 'Analytics')
    and salary > (select avg(salary) from table_1)


-- Write your query here
select
    name,
    department,
    salary,
    
    dense_rank() over (
        partition by department
        order by salary desc
    )
    as salary_rank,
    
    max(salary) over (partition by department) - salary 
    as difference_from_top
    
from Employees  
order by department, salary_rank


-- Write your query here
select 
    month,
    revenue,
    
    dense_rank() over (
        order by revenue desc
    )
    as revenue_rank,
    
    round(
        (revenue - lag(revenue) over (order by month)) * 100.0
        / lag(revenue) over (order by month),
        
        2
    )
    as growth_pct
    
from MonthlyPerformance
order by month

