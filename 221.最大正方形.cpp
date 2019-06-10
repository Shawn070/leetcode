/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形

    在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

    示例:

    输入: 

    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0

    输出: 4

 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i=1; i <= m; i++) {
            for (int j=1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]);
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};

