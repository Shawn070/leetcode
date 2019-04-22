/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode-cn.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (21.82%)
 * Total Accepted:    4.7K
 * Total Submissions: 21.7K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输入: false
 * 
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < sLen) {
            if (j < pLen && p[j] == '*') {  // 匹配*
                match = i;      // 匹配上*的i
                asterisk = j++; // 匹配上*的j，即星号位置，j并跳到下一位置
            } else if (j < pLen && (s[i] == p[j] || p[j] == '?')) { // 匹配 ? 或对应字符，如示例5
                i++;
                j++;
            } else if (asterisk >= 0) { //匹配星号，s中跳过任意匹配星号的字符
                i = ++match;        // i后移一位，不断跳过，以匹配星号对应的任意多字符
                j = asterisk + 1;   // j跳到星号下一个位置，固定的
            } else  // 匹配不上
                return false;
        }
        while (j < pLen &&  p[j] == '*') j++;
        return j == pLen;
    }
};

