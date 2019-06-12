--
-- @lc app=leetcode.cn id=185 lang=mysql
--
-- [185] 部门工资前三高的员工

Employee 表包含所有员工信息，每个员工有其对应的 Id, salary 和 department Id 。

+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
| 5  | Janet | 69000  | 1            |
| 6  | Randy | 85000  | 1            |
+----+-------+--------+--------------+
Department 表包含公司所有部门的信息。

+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
编写一个 SQL 查询，找出每个部门工资前三高的员工。例如，根据上述给定的表格，查询结果应返回：

+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Randy    | 85000  |
| IT         | Joe      | 70000  |
| Sales      | Henry    | 80000  |
| Sales      | Sam      | 60000  |
+------------+----------+--------+

-- 3044 ms
# Write your MySQL query statement below

SELECT d.Name AS Department,
       e.Name AS Employee,
       e.Salary AS Salary
FROM Employee AS e
JOIN Department AS d
ON e.DepartmentId = d.Id
WHERE (
    SELECT COUNT(DISTINCT Salary)
    FROM Employee AS e2
    WHERE e.DepartmentId = e2.DepartmentId
    AND e2.Salary >= e.Salary
) <= 3 
ORDER BY e.DepartmentId, e.Salary DESC;


-- 1684 ms
SELECT d.Name AS Department,
       e.Name AS Employee,
       e.Salary AS Salary
FROM Employee AS e,
     Employee AS e2,
     Department AS d
WHERE d.Id = e.DepartmentId AND e.DepartmentId = e2.DepartmentId
AND e.Salary <= e2.Salary
GROUP BY d.Id, e.Name HAVING COUNT(DISTINCT e2.Salary) <= 3
ORDER BY d.Name, e.Salary DESC;
