/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (24.81%)
 * Total Accepted:    44.4K
 * Total Submissions: 179.1K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

//32 ms	9.4 MB
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int slen = s.length(), pos = 0, posTemp = 0, maxlen = 0;
        if (slen == 0 || slen == 1)
        {
            return s;
        }
        for (int i = 0; i < slen; i++)
        {   //点睛之笔
            if (slen - i  < maxlen / 2) break;  //12 ms	8.6 MB
            // 奇数字符串 例如：qdcbabcdp  qdcb ⬅[a]➡ bcdp, [a]:i
            int j = 0;
            while (i - j >= 0 && i + j <= slen && s[i - j] == s[i + j])
                j++;
            if (2 * j - 1 > maxlen)
            {
                maxlen = 2 * j - 1;
                pos =  i - j + 1;
            }

            // 偶数字符串 例如：qcbaabcp    qcb ⬅[a][a]➡ bcp, [a]:i
            if(s[i] == s[i+1]){             
                j = 0;
                while (i - j >= 0 && i + j <= slen && s[i - j] == s[i + j + 1])
                    j++;
                if (2 * j> maxlen)
                {
                    maxlen = 2 * j;
                    pos = i - j + 1; 
                }
            }
        }
        return s.substr(pos, maxlen);
    }
};


//8 ms	8.6 MB
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int len = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < len;) {
            if (len - i < maxLen / 2) break;
            int left = i, right = i;
            while (right < len - 1 && s[right] == s[right + 1]) ++right;
            i = right + 1;
            while (left > 0 && right < len && s[left - 1] == s[right + 1]) {
                left--; right++;
            }
            if (maxLen < right - left + 1) {
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};