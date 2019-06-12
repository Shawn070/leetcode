--
-- @lc app=leetcode.cn id=178 lang=mysql
--
-- [178] 分数排名
--
# Write your MySQL query statement below

SELECT a.Score, COUNT(DISTINCT b.Score) AS Rank
FROM Scores a,
     Scores b 
WHERE b.Score >= a.Score
GROUP BY a.Id
ORDER BY a.Score DESC;


SELECT Score, 
(SELECT COUNT(DISTINCT Score) 
FROM Scores WHERE Score >= s.Score)AS Rank
FROM Scores s ORDER BY Score DESC;
