/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。
 */
// 使用贪心算法，每次都选择可跳范围内能跳最远的那一步。
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0; // 如果元素低于1，直接返回
        int currReach = 0;          // 当前到达的地方
        int nextReach = nums.at(0); // 下一步到达的地方
        int step = 0;               // 保存需要跳跃的步数
        for (int i = 0; i < nums.size() - 1; ++i) {
            // 在 i 到nextReach间寻找能跳最远下一跳的位置
            nextReach = max(i + nums.at(i), nextReach);
            
            // 如果下一步到达的地方超过数组长度，则结束
            if (nextReach >= nums.size() - 1) {
                return step + 1;
            }
            
            // 如果遍历到当前位置，则跳跃
            if (i == currReach) {
                ++step;
                currReach = nextReach;
            }
        }
        return step;
    }
};

