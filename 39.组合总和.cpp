/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (63.70%)
 * Total Accepted:    15.2K
 * Total Submissions: 23.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 */
class Solution {
    vector<vector<int>> res;
    vector<int> tmp;
public:
    void helper(vector<int>& candidates, int target, int l, int r) {
        if (target == 0){
            res.push_back(tmp);
            return ;
        }
        if (target < 0 || l > r)
            return ;
        tmp.push_back(candidates[l]);
        helper(candidates, target - candidates[l], l, r);
        tmp.pop_back();
        helper(candidates, target, l+1, r);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0, candidates.size() - 1);
        return res;
    }
};

