/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]

 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        DFS(s, 0, 0, ip, res);
        return res;
    }
    
    // start: 第几个元素; step: 第几层（共4层，0~3）; ip: ip地址
    void DFS(string s, int start, int step, string ip, vector<string> &res) {
        //深度到达
        if (start == s.size() && step == 4) {   
            ip.erase(ip.end() - 1);
            res.push_back(ip);
            return;
        }
        //剩余元素过多或过少
        if (s.size() - start > (4 - step) * 3) return ;
        if (s.size() - start < (4 - step)) return ;
        //遍历每层中的每个数
        int num = 0;    //每层中的数字
        for (int i = start; i < start + 3; i++) {
            num = num * 10 + (s[i] - '0');
            if (num <= 255) {
                ip += s[i];
                DFS(s, i + 1, step + 1, ip + ".", res);
            }
            if (num == 0) break;
        }
    }
};

