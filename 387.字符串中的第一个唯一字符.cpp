/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 
 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 

注意事项：您可以假定该字符串只包含小写字母。
 */

// 思路1：暴力法
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.length() == 1) return 0;
        for (int i=0; i < s.length(); i++) {
            bool res = true;
            for (int j = 0; j < s.length(); j++) {
                if (i == j)
                    continue;
                if (s[i] == s[j]) {
                    res = false;
                    break;
                }
            }
            if (res) return i;
        }
        return -1;
    }
};

// 思路2：map<char, int>
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> sMap;
        for (auto ch : s) {
            sMap[ch]++;
        }
        int i = 0;
        for (auto ch : s) {
            if (sMap[ch] == 1)
                return i;
            i++;
        }
        return -1;
    }
};
