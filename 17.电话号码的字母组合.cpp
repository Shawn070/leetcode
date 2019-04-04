/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (48.32%)
 * Total Accepted:    19.7K
 * Total Submissions: 40.9K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string> res;
        for(int i=0; i < digits.length(); i++){
            int index = digits[i] - '0';
            if(!i){ //首次运行，i=0，把button[index]压入res vector
                for(char c : button[index]) 
                    res.push_back(string(1, c));
            }else{
                vector<string> tmp; //创建临时vector
                for(string s:res){  //依次取出res，i>2时，res中的vector.string.length>2
                    for(char c:button[index]) 
                        tmp.push_back(s+string(1, c)); //将s+单个字符压入tmp
                }
                res = tmp;
            }
        }
        return res;
    }
private:
    vector<string> button{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

