SELECT without_name.employee_id, Employees.name, without_name.reports_count, without_name.average_age
FROM
(SELECT sub.reports_to AS employee_id, COUNT(sub.employee_id) AS reports_count, ROUND(AVG(sub.age)) as average_age
FROM (SELECT * FROM Employees WHERE reports_to IS NOT NULL) AS sub
GROUP BY sub.reports_to) AS without_name, Employees
WHERE Employees.employee_id = without_name.employee_id
ORDER BY without_name.employee_id ASC;