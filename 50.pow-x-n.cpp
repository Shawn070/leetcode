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

// (8 ms	8.1 MB)
class Solution {
public:
    double myPow(double x, int n) {
        bitset<32> bit(abs(double(n))); // 用 0 1 来存储需要乘的位置
        double res = 1;     // 需要double(n)，当n=-2^31 (-2,147,483,648) 
        for (int i = bit.size()-1; i >= 0; i--) {
            res *= res;         // x^(n*2) = x^n * x^n
            if (bit[i] == 1)
                res *= x;       // x^n
        }
        return (n > 0) ? res : 1/res;
    }
};

// 快速幂算法:(4 ms	8.4 MB)
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1/x;
            N = -N;
        }
        n = N;
        long double res = 1, base = x;
        while (n) {
            if (n % 2) res *= base;
            base *= base;
            n /= 2;
        }
        return res;
    }
};

// 递归快速幂算法:(4 ms	8.2 MB)
/*
时间复杂度：O(log(n))，每次应用公式 (x^n)^2 = x^(2*n)
空间复杂度：O(log(n))，每次都需要存储 x^(n/2) 的结果
*/
class Solution {
public:
    double fastPow(double x, long long n) {
        if (!n) 
            return 1.0;
        double half = fastPow(x, n/2);
        if (n % 2) 
            return half * half * x;
        else 
            return half * half;
        // return ((n % 2) ? x : 1) * half * half;
    }

    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1/x;
            N = -N;
        }
        return fastPow(x, n);
    }
};

// 迭代快速幂算法:(0 ms	8.4 MB)
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1/x;
            N = -N;
        }
        double res = 1;
        double cur = x;
        for (long long i = N; i; i /= 2) {
            if (i % 2)
                res *= cur;
            cur *= cur;
        }
        return res;
    }
};


// 暴力法:(超出时间限制)
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        double res = 1;
        for (long long i = 0; i < n; i++)
            res = res * x;
        return res;
    }
};

