/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int u = 0, d = m - 1, l = 0, r = n - 1;
        int p = 0;
        vector<int> order(m * n);
        while (u <= d && l <= r) {
            for (int col = l; col <= r; col++) {    //顶行
                order[p++] = matrix[u][col];
            }
            if (++u > d) break;
            for (int row = u; row <= d; row++) {    //右列
                order[p++] = matrix[row][r];
            }
            if (--r < l) break;
            for (int col = r; col >= l; col--) {    //底行
                order[p++] = matrix[d][col];
            }
            if (--d < u) break;
            for (int row = d; row >= u; row--) {    //左列
                order[p++] = matrix[row][l];
            }
            if (++l > r) break;
        }
        return order;
    }
};

