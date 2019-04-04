/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (33.73%)
 * Total Accepted:    38.7K
 * Total Submissions: 114.6K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */
/*
思路1
很简单的思路：就是遍历两个数组，在里面找到第i个大元素，
这个应该还是比较简单的，时间复杂度O(m+n)。

用2个变量分别指向两个数组，每次取较小的一个，然后将其
指针后移动。但是这里有个问题，就是奇偶判断，如果是奇数
，中位数是num[mid]，但是如果是偶数，是(num[mid]+num[mid-1])/2。
这里我的做法是把num[mid]看作(num[mid]+num[mid - flags])/2。
如果是偶数1,奇数0 -> flags。
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 == 0) return MedofArray(nums2);
        if(n2 == 0) return MedofArray(nums1);
        vector<int> nums3;
        int size = n1 + n2;
        int mid  = size / 2;
        int flag = !(size % 2);
        int i, n1Ind, n2Ind;
        double a, b;
        for(i = n1Ind = n2Ind = 0; i < size; ++i){
            a = n1Ind < n1 ? nums1[n1Ind] : INT_MAX;
            b = n2Ind < n2 ? nums2[n2Ind] : INT_MAX;
            if(a < b){
                nums3.push_back(nums1[n1Ind]);
                n1Ind++;
            }else{
                nums3.push_back(nums2[n2Ind]);
                n2Ind++;
            }
            if(i == mid) break;
        }

        return (nums3[mid] + nums3[mid - flag]) / 2.0;
    }
    double MedofArray(vector<int>& nums){
        int mid  = nums.size() / 2;
        int flag = !(nums.size() % 2);
        return (nums[mid] + nums[mid - flag]) / 2.0;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    }
};

