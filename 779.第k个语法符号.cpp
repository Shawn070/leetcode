/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号

在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。

给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）


例子:

输入: N = 1, K = 1
输出: 0

输入: N = 2, K = 1
输出: 0

输入: N = 2, K = 2
输出: 1

输入: N = 4, K = 5
输出: 1

解释:
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001

注意：

N 的范围 [1, 30].
K 的范围 [1, 2^(N-1)].

 */
// 解题连接：https://leetcode-cn.com/explore/orignial/card/recursion-i/260/conclusion/1232/

// 方法1：递归（父变体）
/* 第 K 位的父位应该是第 (K+1) / 2 位。如果父位是 0，那么这一位就是
 * 1 - (K%2)。如果父位是 1，那么这一位就是 K%2。
 */
class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        return (1 - K%2) ^ kthGrammar(N - 1, (K + 1) / 2);
    }
};

