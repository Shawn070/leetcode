/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (69.20%)
 * Total Accepted:    18.8K
 * Total Submissions: 27.2K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recurParenthesIs("", n, 0, &res);
        return res;
    }
    void recurParenthesIs(const string& path, int leftNum, int rightNum, vector<string>* res){
        // leftNum表示还可以用几个左括号的数量，rightNum表示还可以用几个右括号的数量
        if (leftNum == 0 && rightNum == 0){
            if (!path.empty())  res->push_back(path);
            return;
        }
        if (leftNum  > 0) recurParenthesIs(path + '(', leftNum - 1, rightNum + 1, res);
        if (rightNum > 0) recurParenthesIs(path + ')', leftNum, rightNum -1, res);
    }
};

