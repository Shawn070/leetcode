--
-- @lc app=leetcode.cn id=180 lang=mysql
--
-- [180] 连续出现的数字

编写一个 SQL 查询，查找所有至少连续出现三次的数字。

+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+
例如，给定上面的 Logs 表， 1 是唯一连续出现至少三次的数字。

+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+

--
# Write your MySQL query statement below

SELECT DISTINCT l1.Num ConsecutiveNums
FROM Logs l1
JOIN Logs l2 ON l1.Num = l2.Num
JOIN Logs l3 ON l1.Num = l3.Num
WHERE (l1.Id + 1) = l2.Id
    AND (l2.Id + 1) = l3.Id;
