/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
 */
class Solution {
public:
    double myPow(double x, int n) {
        bitset<32> bit(abs(double(n))); // 用 0 1 来存储需要乘的位置
        double res = 1;     // 需要double(n)，当n=-2^31 (-2,147,483,648) 
        for (int i = bit.size()-1; i >= 0; i--) {
            res *= res;
            if (bit[i] == 1)
                res *= x;
        }
        return (n > 0) ? res : 1/res;
    }
};

