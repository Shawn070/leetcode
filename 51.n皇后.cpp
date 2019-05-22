/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

 */
class Solution {
void search(int n, int r, vector<string>& v, vector<vector<string>>& vv, vector<int>& forward, vector<int>& backward, vector<int>& columns) {
    if (r == n) vv.push_back(v);
    for (int c=0; c < n; c++) {
        if (!forward[r+c] && !backward[r+n-c-1] && !columns[c]) {
            vv[r][c] = 'Q';
            forward[r+c] = backward[r+n-c-1] = columns[c] = 1;
            search(n, r+1, v, vv, forward, backward, columns);
            vv[r][c] = '.';
            forward[r+c] = backward[r+n-c-1] = columns[c] = 0;
        }
    }
}
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> forward(2*n-1), backward(2*n-1), columns(n);
        vector<vector<string>> vv;
        vector<string> v(n, string(n, '.'));
        search(n, 0, v, vv, forward, backward, columns);
        return vv;
    }
};

