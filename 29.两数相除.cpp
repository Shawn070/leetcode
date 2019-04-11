/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (17.85%)
 * Total Accepted:    10.6K
 * Total Submissions: 59.6K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 
 * 说明:
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */
// Basic idea: a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b))
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        if (divisor==0) return INT_MAX;
        long long res=double(exp(log(fabs(dividend))-log(fabs(divisor))));
        if ((dividend<0)^(divisor<0)) res=-res; // ^：异或符号
        if (res>INT_MAX) res=INT_MAX;
        return res;
    }
};

