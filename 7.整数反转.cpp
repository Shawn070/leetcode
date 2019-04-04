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
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        int upNum = 0;
        if(x == 0) return 0;
        while(upNum == 0){
            upNum = x % 10;
            x /= 10;
        }
        x = x*10 + upNum;
        while(x != 0){
            upNum = x % 10;
            x /= 10;              
            if(ret > INT_MAX/10 || (ret == INT_MAX) && upNum > 7) return 0;
            if(ret < INT_MIN/10 || (ret == INT_MIN) && upNum < -8) return 0;
            ret = ret*10 + upNum;
        }
        return ret;
    }
};

