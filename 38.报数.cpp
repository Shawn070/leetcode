/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (48.97%)
 * Total Accepted:    26.7K
 * Total Submissions: 54.6K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        string curr_str;
        curr_str += '1';
        for (int i=0; i < n - 1; i++) { // 遍历n，跳过第一个
            string buffer;
            for (int index = 0; index < curr_str.size(); index++){ //遍历前一个 curr_str，输出下一个到 buffer
                int cnt = 1;
                while (index + 1 < curr_str.size() && curr_str[index + 1] == curr_str[index]) { //下一个字符匹配则计数
                    index++;
                    cnt++;
                }
                buffer.push_back(cnt + '0');        // 替换buffer第一个字符，cnt + '0'为cnt数字的字符
                buffer.push_back(curr_str[index]);  // 压入curr_str[index]首字符后，进入下一个循环，index++
            }
            curr_str = buffer;  // 更新 curr_str
        }
        return curr_str;
    }
};

