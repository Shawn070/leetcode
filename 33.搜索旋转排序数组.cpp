/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.33%)
 * Total Accepted:    20.4K
 * Total Submissions: 56.3K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         for(int i = 0; i < nums.size(); i++){ 
//             if(nums[i]==target) return i; 
//         } 
//         return -1; 
//     }
// };


// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         auto it = find(nums.begin(), nums.end(), target);
//         if (it == nums.end()) return -1;
//         else return it - nums.begin();
//     }
// };


/*
nums[0] <= nums[mid],（0-mid不包含旋转）且nums[0] <= target <= nums[mid]时high向前规约；

nums[mid] < nums[0]（0-mid包含旋转），target <= nums[mid] < nums[0]时向前规约（target在旋转位置到mid之间）

nums[mid] < nums[0]，nums[mid] < nums[0] <= target时向前规约（target在0到旋转位置之间）

其他情况向后规约 也就是说nums[mid] < nums[0]，nums[0] > target，target > nums[mid]三项均为真或者只有一项为真时向后规约。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l < r) {
            mid = (l + r) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid])) 
                l = mid + 1;
            else 
                r = mid;
        }
        return l == r && nums[l] == target ? l : -1;
    }
};
