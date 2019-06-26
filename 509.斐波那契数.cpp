/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数

斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
给定 N，计算 F(N)。

 

示例 1：

输入：2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
示例 2：

输入：3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
示例 3：

输入：4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
 

提示：

0 ≤ N ≤ 30

 */

// 直接计算（8 ms	8.3 MB）
class Solution {
public:
    int fib(int N) {
        if (N < 2) return N;
        
        int n1 = 0, n2 = 1;
        
        for (int i=2; i <= N; i++) {
            n1 += n2;
            swap(n1, n2);
        }
        return n2;
    }
};

// 递归：避免重复计算（8 ms	8.5 MB）
class Solution {
public:
    int fib(int N) {
        map<int, int> m;
        
        return helper(N, m);
    }
    int helper(int N, map<int, int>& m) {
        int res;
        if (m.find(N) != m.end()) return m[N];
        if (N < 2) 
            res = N;
        else 
            res = helper(N-1, m) + helper(N-2, m);
        m.insert(pair<int, int>(N, res));
        return res;
    }
};

