SELECT e.name AS name
FROM Employee e JOIN (
    SELECT managerId, COUNT(*) AS reports FROM Employee GROUP BY managerID
    ) AS m ON e.id = m.managerId
WHERE reports>4