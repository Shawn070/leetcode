/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量

给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。

示例:

输入:
[[0,0],[1,0],[2,0]]

输出:
2

解释:
两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]

 */

// 求一点与其他点之间的距离，用unordered_map存储，若同一距离出现多次，则可以形成回旋镖。
// 同一距离出现 n 次，由数字规律可推出回旋镖的数量 sum = n*(n-1) 。

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        unordered_map<int, int> um;
        for (int i=0; i < points.size(); i++) {
            for (int j=0; j < points.size(); j++) {
                if (i == j) continue;
                auto x = points[i][0] - points[j][0];
                auto y = points[i][1] - points[j][1];
                um[x*x + y*y]++;
            }
            for (auto &x : um)
                res += x.second * (x.second - 1);
            um.clear();
        }
        return res;
    }
};

