/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词

给定一个字符串，逐个翻转字符串中的每个单词。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

进阶：

请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。

 */

// string str.substr(nStart, nLength) 
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int pos = 0;    //记录单词开始的位置
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (i > pos)    //单词结尾
                    res = s.substr(pos, i - pos) + ' ' + res;
                pos = i + 1;
            } else if (i == s.length() - 1) {   //最后一个单词后没有空格的情况
                res = s.substr(pos, s.length() - pos) + ' ' + res;
            }
        }
        return res.substr(0, res.length() - 1); //去除最后一个空格
    }
};

