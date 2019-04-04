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
        {
            // 奇数字符串
            int j = 0;
            while (i - j >= 0 && i + j <= slen && s[i - j] == s[i + j])
                j++;
            if (2 * j - 1 > maxlen)
            {
                maxlen = 2 * j - 1;
                pos =  i - j + 1;
            }

            // 偶数字符串
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

        // int len = s.length();
        // if (len == 1 || len == 0)
        //     return s;
        // int max_len = 1, start = -1;    // 最长回文string的起始位置，max_len是最长回文长度
        // for (int i = 0; i < len; i++)
        // {
        //     int l = i - 1, r = i + 1;       // left, right
        //     // 把一个字符作为中心
        //     while (l >= 0 && r <= len - 1 && s[l] == s[r]){ --l; ++r; }
        //     if (r - l - 1 > max_len)
        //     {
        //         max_len = r - l - 1;
        //         start = l + 1;
        //     }

        //     if (i != len - 1 && s[i] == s[i + 1])
        //     {
        //         l = i - 1, r = i + 2;
        //         // 两个相同字符作为中心
        //         while (l >= 0 && r <= len - 1 && s[l] == s[r]){ --l; ++r; }
        //         if (r - l - 1 > max_len)
        //         {
        //             max_len = r - l - 1;
        //             start = l + 1;
        //         }
        //     }
        // }
        // if(start == -1)     // 当没有回文子串的时候，随便返回一个就行，为保证不会越界，返回第一个就行
        //     return string() + s[0];
        // return s.substr(start, max_len);
    }
};
