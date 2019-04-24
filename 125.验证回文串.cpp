/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 * 
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

 */
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            // left 非字符则转到下一个
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            // right 非字符则转到上一个
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            // 检测两个字符知否相等
            if (tolower(s[l++]) != tolower(s[r--])) 
                return false;
        }
        return true;
    }
};

