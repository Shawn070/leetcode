/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和

给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

 */
class Solution {
public:
	string addBinary(string a, string b) {
		if (a.length() < b.length())
			swap(a, b);
		int i = a.length(), j = b.length();
		while (i--) {
			if (j) 
				a[i] += b[--j] & 1;
				//等于 a[i] += b[--j] - '0';
			if (a[i] > '1') {
				a[i] -= 2;
				if (i) a[i - 1]++; else a = '1' + a;
			}
		}
		return a;
	}
};

