/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？



例如，上图是一个7 x 3 的网格。有多少可能的路径？

说明：m 和 n 的值均不超过 100。

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28

 */

//思路：递归（超时）
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0)
            return 0;
        else if (m == 1 || n == 1)
            return 1;
        else if (m == 2 && n == 2)
            return 2;
        else if ((m == 3 && n == 2) || (m == 2 && n == 3))
            return 3;
        int paths = 0;
        paths += uniquePaths(m - 1, n);
        paths += uniquePaths(m, n - 1);
        return paths;
    }
};

//思路：递归 + 记忆（0 ms	8.2 MB）
class Solution {
public:
    int a[101][101]={0};
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0)
            return 0;
        else if (m == 1 || n == 1)
            return 1;
        else if (m == 2 && n == 2)
            return 2;
        else if ((m == 3 && n == 2) || (m == 2 && n == 3))
            return 3;
        if (a[m][n] > 0)
            return a[m][n];
        a[m - 1][n] = uniquePaths(m - 1, n);
        a[m][n - 1] = uniquePaths(m, n - 1);
        a[m][n] = a[m - 1][n] + a[m][n - 1];
        return a[m][n];
    }
};

