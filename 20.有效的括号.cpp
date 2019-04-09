/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.27%)
 * Total Accepted:    61.9K
 * Total Submissions: 166.1K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> sstack; //利用栈
        for(int i = 0;i < s.length(); ++i){
            if(sstack.size() == 0){ //空栈压入
                sstack.push(s[i]);
            }else if (isSym(sstack.top(), s[i])){ //判断栈顶字符是否匹配
                sstack.pop();
            }else{
                sstack.push(s[i]);
            }
        }
        return sstack.size() == 0;  //利用空栈判断是否都匹配
    }
private:
    bool isSym(char c1, char c2){   //判断两符号是否相同
        return ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}'));
    }
};

