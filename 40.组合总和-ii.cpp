/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (54.66%)
 * Total Accepted:    10.8K
 * Total Submissions: 19.8K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        combHelper(num, 0, num.size(), target, vector<int>(), result);
        return result;
    }
    
    void combHelper(vector<int>& a, int start, int n, int target, 
    vector<int> cur_vec, vector<vector<int> >& result) {
        if (target == 0) {  //满足则压入result
            result.push_back(cur_vec);
            return;
        }
        int i = start;
        while(i < n  && target-a[i] >= 0) { //遍历后续
            if (i == start || a[i] != a[i-1]) {
                cur_vec.push_back(a[i]);
                combHelper(a, i+1, n, target-a[i], cur_vec, result);
                cur_vec.pop_back(); //遍历完成后弹出不符合的数
            }
            i++;
        }
    }
};

