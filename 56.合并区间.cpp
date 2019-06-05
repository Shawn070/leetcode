/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间

    给出一个区间的集合，请合并所有重叠的区间。

    示例 1:

    输入: [[1,3],[2,6],[8,10],[15,18]]
    输出: [[1,6],[8,10],[15,18]]
    解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
    示例 2:

    输入: [[1,4],[4,5]]
    输出: [[1,5]]
    解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

 */
class Solution {
public:
    static int cmp(const vector<int> &a,const vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(), cmp);
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < inter.size()) {
            int a1 = inter[i][0], a2 = inter[i][1];
            j = i + 1;
            while (j < inter.size() && a2 >= inter[j][0]){
                a2 = max(a2, inter[j][1]);
                j++;
            }
            res.push_back(vector<int>{a1, a2});
            if (j >= inter.size()) break;
            i = j;
        }
        return res;
    }
};

class Solution {
public:
    static int cmp(const vector<int> &a,const vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(), cmp);
        vector<vector<int>> res;
        if (inter.empty()) return res;
        res.push_back(inter[0]);
        for (int i = 1; i < inter.size(); i++) {
            if (inter[i][0] <= res.back()[1]) {
                vector<int> temp = {res.back()[0], max(inter[i][1], res.back()[1])};
                res.pop_back();
                res.push_back(temp);
            } else {
                res.push_back(inter[i]);
            }
        }
        return res;
    }
};

