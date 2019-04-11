/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.39%)
 * Total Accepted:    8.9K
 * Total Submissions: 33.8K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */

// 太难了，没看懂
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;
        int cnt = 0; // count of '('
        vector<int> dp(s.size() + 1, 0); //save right size of (), s.front()=0

        for (size_t i = 1; i <= s.size(); i++) {
            if (s[i-1] == '('){
                ++cnt;
            } else {
                if (cnt > 0) {
                    cnt--;
                    dp[i] = 2;
                    if (s[i-2] == ')'){
                        dp[i] += dp[i-1];
                    }
                    dp[i] += dp[i - dp[i]];
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

