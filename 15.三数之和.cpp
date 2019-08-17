/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.66%)
 * Total Accepted:    45.3K
 * Total Submissions: 209.3K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
// 272 ms	14.6 MB
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1]) j++; //j < k ：j++后j更新
                    while(j < k && nums[k] == nums[k - 1]) k--; //j < k ：k++后k更新
                    ++j, --k;
                }
                else if(nums[i] + nums[j] + nums[k] < 0) j++;
                else k--;
            }
        }
        return res;
    }
};

// 136 ms	14.6 MB
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() <= 2) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int a = nums[i];
            if (a > 0) break;
            if (i > 0 && a == nums[i - 1]) continue;
            for (long j = i + 1, k = nums.size() - 1; j < k;) {
                int b = nums[j];
                int c = nums[k];
                int value = a + b + c;
                if (value == 0) {
                    res.push_back(vector<int>({a, b, c}));
                    while (j < k && b == nums[++j]);
                    while (j < k && c == nums[--k]);
                }
                else if (value > 0)
                    k--;
                else 
                    j++;
            }
        }
        return res;
    }
};