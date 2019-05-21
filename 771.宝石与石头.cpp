/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

//方法一：时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for (char cj : J) {
            for (char cs : S) {
                if (cj == cs)
                    ++res;
            }
        }
        return res;
};

//方法一：时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int map[52] = {0};
        int res = 0;
        for (int i=0; i < S.length(); i++) {
            if (S[i] >= 'a')
                map[S[i] - 'a']++;
            else
                map[S[i] - 'A' + 26]++;
        }
        for (int j=0; j < J.length(); j++) {
            if (J[j] >= 'a')
                res += map[J[j] - 'a'];
            else
                res += map[J[j] - 'A' + 26];
        }
        return res;
    }
};

