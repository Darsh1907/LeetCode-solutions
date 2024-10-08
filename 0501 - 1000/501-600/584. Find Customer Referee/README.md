# 584. Find Customer Referee
## (Easy)

Table: `Customer`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
```

In SQL, id is the primary key column for this table.<br>
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.
<br>

Find the names of the customer that are not referred by the customer with `id = 2`.
<br>
Return the result table in **any order**.
<br>
The result format is in the following example.
<br>
 

Example 1:

Input: <br>

```
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
```

Output: 

```
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+
```