/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

 */
// sstringstream
class Solution {
public:
    string reverseWords(string s) {
        string res, word;
        stringstream iss(s);
        while (iss >> word) {
            reverse(word.begin(), word.end());
            res += word + ' ';
        }
        res.pop_back();
        return res;
    }
};

// 双指针
class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0;   //双指针
        for (int n = 0; n < s.size(); n++) {
            if (s[n] == ' ' || (n == s.size() - 1 && n++)) {
                r = n - 1;
                while (l < r) {
                    swap(s[l++], s[r--]);
                }
                l = n + 1;
            }
        }
        return s;
    }
};


