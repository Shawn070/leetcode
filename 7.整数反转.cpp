/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (32.21%)
 * Total Accepted:    102.5K
 * Total Submissions: 318.1K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */
// 提前判断退出 8 ms	8.2 MB
// INT_MAX =  2147483647 
// INT_MIN = -2147483648
class Solution {
public:
    int reverse(int x) {
        int preNum = 0;
        while (x != 0) {
            int temp = x % 10;
            x /= 10;
            if (preNum > INT_MAX / 10 || (preNum == INT_MAX / 10 && temp > 7))
                return 0;
            if (preNum < INT_MIN / 10 || (preNum == INT_MIN / 10 && temp < -8))
                return 0;
            preNum = preNum * 10 + temp;
        }
        return preNum;
    }
};

// 用long避免溢出问题 12 ms	8.1 MB
class Solution {
public:
    int reverse(int x) {
        long ret = 0;
        while (x != 0) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return (ret > INT_MAX || ret < INT_MIN) ? 0 : ret;
    }
};
