/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形

还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例 1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。
注意:

给定的火柴长度和在 0 到 10^9之间。
火柴数组的长度不超过15。

 */
// DFS，负数标记已访问数据

class Solution {
public:
    bool dfs(vector<int> &nums, int curLen) {
        if (curLen == 0) return true;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > curLen) return false;
            if (nums[i] > 0) {
                nums[i] = -nums[i];                         //标记访问数据
                if (dfs(nums, curLen - abs(nums[i])))
                    return true;
                nums[i] = abs(nums[i]);                     //恢复
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%4) return false;                            //余数不为零一定不能构成
        
        sort(nums.begin(), nums.end(), greater<int>());     //升序排序，贪心选择长的构建边
        for (int i=0; i<3; ++i) {                           //只需判断是否构建出3条长为sum/4的边长
            if (!dfs(nums, sum/4))  return false;
        }
        return true;
    }
};

