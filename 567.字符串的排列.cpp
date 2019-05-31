/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列

给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

1.输入的字符串只包含小写字母
2.两个字符串的长度都在 [1, 10,000] 之间

 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int windowSize = s1.size();
        vector<int> hashmap1(26, 0);
        vector<int> hashmap2(26, 0);
        for (int i = 0; i < windowSize; i++) {
            hashmap1[s1[i] - 'a']++;
            hashmap2[s2[i] - 'a']++;
        }
        for (int i = windowSize; i < s2.size(); i++) {
            if (hashmap1 == hashmap2) return true;
            hashmap2[s2[i - windowSize] - 'a']--;
            hashmap2[s2[i] - 'a']++;
        }
        return hashmap1 == hashmap2;
    }
};

