/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串

给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。

 */

// 判断相同字符在相同位置
/*
string st1("babbabab");
cout << st1.find('a') << endl;//1   由原型知，若省略第2个参数，则默认从位置0（即第1个字符）起开始查找
cout << st1.find('a', 2) << endl;//4   在st1中，从位置2（b，包括位置2）开始，查找字符a，返回首次匹配的位置，若匹配失败，返回npos
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for (int i=0; i < s.size(); i++) {
            if (s.find(s[i]) != t.find(t[i]))
                return false;
        }
        return true;
    }
};

