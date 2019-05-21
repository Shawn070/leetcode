/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度

给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5

 */

//方法一：使用 stringstream 
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        while (ss >> word) {}   //字符串输入输出流自动过滤空格
        return word.length();   //读取到最后一个单词
    }
};

//方法二：使用 str.rfind(' ');
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.rfind(' ');
        while (index == s.length() - 1) {
            if (s.empty()) return 0;
            s.erase(index);         //擦除末尾 空格
            index = s.rfind(' ');   //查找最后一个空格
            //index = s.find_last_of(' ');  //相同的
        }
        return s.length() - index - 1;
    }
};

