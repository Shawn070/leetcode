/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数

给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:

输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
示例 2:

输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

 */
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i=0; i < points.size(); i++) { //遍历每个点与其他点的斜率
            int samePoints = 1;                 //相同点的个数
            unordered_map<long double, int> um;      //存储斜率
            for (int j=i+1; j < points.size(); j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    samePoints++;               //相同点
                else if (points[i][0] == points[j][0])
                    um[INT_MAX]++;              //x相同
                else {
                    long double slope = (long double)(points[i][1] - points[j][1]) / (long double)(points[i][0] - points[j][0]);   // int / int = int，要转成 double
                    um[slope]++;                //一般点
                }
            }
            int localMax = 0;
            for (auto &x : um) {
                localMax = max(localMax, x.second);
            }
            localMax += samePoints;
            res = max(res, localMax);
        }
        return res;
    }
};

