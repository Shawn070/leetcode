/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数

给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False

 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num == 0 || num == 1) return true;
        int l = 0, r = num;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            // 不要用mid * mid，会溢出
            if (mid == num*1.0 / mid) 
                return true;
            if (mid > num*1.0 / mid) 
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return false;
    }
};

