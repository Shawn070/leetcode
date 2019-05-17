/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III

给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的
差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false

 */

/*
思路：设置一个 k 大小的滑动窗口
My idea is to preserve a sliding window containing nearest k numbers, 
and check if next number collides to the numbers in the window.
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k == 0) return false;
        deque<int> windows_deq;
        multiset<long> windows;
        for (int i=0; i < nums.size(); i++) {
            if (windows.size() > k) {
                int num = windows_deq.front();
                windows_deq.pop_front();
                windows.erase(windows.find(num));
            }
            //返回指向大于（或等于）某值的第一个元素的迭代器
            auto it = windows.lower_bound((long)nums[i] - (long)t); 
            if (it == windows.end() || *it > (long)nums[i] + (long)t) {
                //没有找到
                windows_deq.push_back(nums[i]);
                windows.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }
};

