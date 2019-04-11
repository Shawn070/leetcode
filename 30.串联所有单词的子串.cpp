/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (25.33%)
 * Total Accepted:    5.7K
 * Total Submissions: 22.3K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty())  return res;
        int m = s.size(), n = words.size(), w = words[0].size();
        map<string, int> m1; //用map存储各个单词的数目
        for (auto &a : words) ++m1[a];
        for (int i=0; i <= m - n*w; ++i) { //遍历 s 中的 n*w 长度的子字符串
            int j = 0;
            map<string, int> m2;    //存储 s 中已用 words 子字符串的数目
            for (; j < n; ++j) {    //循环在 s 中查找 words 中的单词
                string t = s.substr(i + j*w, w);    //依次取出 s 中子字符串
                if(m1.find(t) == m1.end()) break;   //没找到则退出
                ++m2[t];            //找到则存储已找到单词数目
                if(m2[t] > m1[t]) break;    //找到的单词数目 >words 中单词的数目则退出
            }
            if (j == n) res.push_back(i);   //将找符合的子字符串首地址压入 res
        }
        return res;
    }
};

