/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (34.81%)
 * Total Accepted:    15.4K
 * Total Submissions: 44.4K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); //排序
        if(nums.size() < 4) return {};
        vector<vector<int>> res;
        if(nums.size() == 4 && target == nums[0]+nums[1]+nums[2]+nums[3]) {
            res.push_back({nums[0], nums[1], nums[2], nums[3]});
            return res;
        }
             
        int fourSum = nums[0]+nums[1]+nums[2]+nums[3]; //4数和变3数和
        for(int i=0; i < nums.size() - 3; ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue; //去重
            int newTarget = target - nums[i];   //3数和变2数和
            for(int j=i+1; j < nums.size() - 2; ++j){
                if (j > i+1 && nums[j] == nums[j - 1]) continue; //去重
                int newTarget2 = newTarget -nums[j];
                int m = j + 1, n = nums.size() - 1;
                while(m < n){   //用两数和解题思路
                    if(nums[m] + nums[n] == newTarget2){
                        res.push_back({nums[i], nums[j], nums[m], nums[n]});
                        while(m < n && nums[m] == nums[m + 1]) ++m; //去重
                        while(m < n && nums[n] == nums[n - 1]) --n; //去重
                        ++m, --n;
                    }else if(nums[m] + nums[n] < newTarget2) ++m;
                    else --n;
                }
            }
        }
        return res;
    }
};

