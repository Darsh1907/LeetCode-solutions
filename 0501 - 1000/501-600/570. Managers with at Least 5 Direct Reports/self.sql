SELECT name
FROM (SELECT A.name, A.id FROM Employee A, Employee B WHERE A.id = B.managerId) as E 
GROUP BY id 
HAVING COUNT(id) >= 5;