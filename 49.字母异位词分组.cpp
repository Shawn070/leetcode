/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序
 */
// 思路：采用无序图，unordered_map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) { //遍历每个字符串
            string t = s;
            sort(t.begin(), t.end());   // 将无序字符串 s 排序为 t
            mp[t].push_back(s);         // 排序后放入无序图，t作为主键，s作为键值
        }
        vector<vector<string>> res;
        for (auto p : mp) {
            res.push_back(p.second);    // 将键值压入 res
        }
        return res;
    }
};

