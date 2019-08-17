/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (56.01%)
 * Total Accepted:    91.3K
 * Total Submissions: 163.1K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// 	36 ms	8 MB
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        int count = 1;
        int tempx = x;
        int m = 0, n=0;
        while(tempx/=10) ++count;
        while(count>1){
            m = x/pow(10, --count);
            n = x%10;
            if(m != n) return false;
            x /= 10;
            tempx = pow(10, --count);
            x %=tempx;
        }
        return true;
    }
};

// 16 ms	8.1 MB
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x != 0 && x % 10 == 0) 
            return 0;
        
        int res=0;
        while (x > res) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == x || res / 10 == x;
    }
};