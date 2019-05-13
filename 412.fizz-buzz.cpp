/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 * 
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 * 
 */

/* note:
数字——>字符串:
string tmp = to_string(i);

字符串——>字符：
stoi(); string 转换为int
stol(); string 转换为long
stoul(); string 转换为unsigned long
stoll(); string 转换为long long
stoull(); string 转换为unsigned long long
stof(); string 转换为float
stod(); string 转换为double
stold(); string 转换为long double
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i=1; i <= n; i++) {
            if (i%15 == 0)
                ans.push_back("FizzBuzz");
            else if (i%3 == 0)
                ans.push_back("Fizz");
            else if (i%5 == 0)
                ans.push_back("Buzz");
            else {
                string tmp = to_string(i);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

