# Write your MySQL query statement below
Select (
    SELECT DISTINCT salary 
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) as SecondHighestSalary