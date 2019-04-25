/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.62%)
 * Total Accepted:    66.4K
 * Total Submissions: 203.4K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res=strs[0]; // 取第一个字符串
        for(int i=1; i<strs.size(); i++){   // 遍历后续字符串
            string temp;
            for(int j=0; j<strs[i].size() && j<res.size(); j++){    // 遍历两字符串相同
                if(res[j] == strs[i][j]){
                    temp.push_back(res[j]);
                } 
                else break;
            }
            res = temp; // 更新前两个字符的最长公共前缀
        }
        return res;
    }
};

