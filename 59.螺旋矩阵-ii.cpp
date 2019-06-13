/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

 */

// 4ms
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int cnt = 1, j = 0;
        while (cnt <= n * n) {
            for (int i = j; i < n - j; i++)  
                res[j][i] = cnt++;
            for (int i = j + 1; i < n - j; i++)
                res[i][n - 1 - j] = cnt++;
            for (int i = n - 2 - j; i >= j; i--)
                res[n - 1 - j][i] = cnt++;
            for (int i = n - 2 - j; i > j; i--)
                res[i][j] = cnt++;
            
            ++j;
        }
        return res;
    }
};

// 12ms
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int top, left, index, right, down;
        top = left = index = 0, right = down = n - 1;
        while (top <= down && left <= right) {
            for (int i = left; i <= right; i++) 
                res[top][i] = ++index;
            top++;
            for (int i = top; i <= down; i++)
                res[i][right] = ++index;
            right--;
            for (int i = right; i >= left; i--)
                res[down][i] = ++index;
            down--;
            for (int i = down; i >= top; i--) 
                res[i][left] = ++index;
            left++;
        }
        return res;
    }
};
