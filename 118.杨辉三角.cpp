/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

 */

// 方法一：
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (!numRows) return res;
        res.push_back({1});
        for (int i=1; i < numRows; i++) {
            vector<int> vec;
            for (int m = 0; m < i + 1; m++)
                vec.push_back(1);
            for (int j=1; j < vec.size()-1; j++) {
                vec[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(vec);
        } 
        return res;
    }
};

// 方法二：
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> row;
        for (int i = 0; i < numRows; i++) {
            row.push_back(1);
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j - 1] + row[j];
            }
            res.push_back(row);
        }
        return res;
    }
};



