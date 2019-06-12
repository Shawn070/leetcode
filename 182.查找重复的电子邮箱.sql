--
-- @lc app=leetcode.cn id=182 lang=mysql
--
-- [182] 查找重复的电子邮箱
--
-- Write your MySQL query statement below

-- 	711 ms
SELECT Email FROM Person 
GROUP BY Email
HAVING COUNT(Email) > 1;

-- 744 ms
SELECT DISTINCT p1.Email FROM Person p1
INNER JOIN Person p2
ON p1.Email = p2.Email
WHERE p1.Id <> p2.Id;

-- 551 ms
SELECT DISTINCT p1.Email 
FROM Person p1,
     Person p2
WHERE p1.Email = p2.Email
    AND p1.Id != p2.Id;



