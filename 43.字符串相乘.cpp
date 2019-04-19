/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (38.18%)
 * Total Accepted:    13.9K
 * Total Submissions: 36.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */
/*
 Compute the ones-digit, then the tens-digit, then the hundreds-digit,
 etc. For example when multiplying 1234 with 5678, the thousands-digit 
 of the product is 4\*5 + 3\*6 + 2\*7 + 1\*8 (plus what got carried 
 from the hundreds-digit).
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.length() - 1;
        int n = num2.length() - 1;
        int carry = 0;
        string res;
        for (int i = 0; i <= m+n || carry; ++i) {
            for (int j = max(0, i-n); j <= min(i, m); ++j) {
                carry += (num1[m-j] - '0') * (num2[n-i+j] - '0');
            }
            res += carry % 10 + '0';
            carry /= 10;
        }
        reverse(begin(res), end(res));
        return res;
    }
};

