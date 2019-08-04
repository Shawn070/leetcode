/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] ????
 * 
???????? nums ?????? target????????????????? ?? ??????????????

???????????????????????????????????????

??:

?? nums = [2, 7, 11, 15], target = 9

?? nums[0] + nums[1] = 2 + 7 = 9
???? [0, 1]

 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;
        vector<int> b(2, -1);
        for (int i=0; i < nums.size(); i++) {
            if (a.count(target - nums[i]) > 0) {
                b[0] = a[target - nums[i]];
                b[1] = i;
                break;
            }
            a[nums[i]] = i;
        }
        return b;
    }
};