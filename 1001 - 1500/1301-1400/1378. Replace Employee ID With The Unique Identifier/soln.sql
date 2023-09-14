-- select *
-- from Employees left join EmployeeUNI on Employees.id = EmployeeUNI.id;

select EmployeeUNI.unique_id as unique_id, Employees.name as name
from Employees LEFT JOIN EmployeeUNI on Employees.id = EmployeeUNI.id;