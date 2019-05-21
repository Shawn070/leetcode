/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.35%)
 * Total Accepted:    85.6K
 * Total Submissions: 302.1K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashMap[256] = {0}, res = 0, left = 0;
        for(int i =0; i < s.size(); ++i){
            if(hashMap[s[i]] == 0 || hashMap[s[i]] < left){
                res = max(res, i - left + 1);
            }
            else{
                left = hashMap[s[i]];
            }
            hashMap[s[i]] = i + 1;
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dict[256] = {-1};
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

