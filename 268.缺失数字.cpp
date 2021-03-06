/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] ????

?????? 0, 1, 2, ..., n ? n ???????? 0 .. n ??????????????

?? 1:

??: [3,0,1]
??: 2
?? 2:

??: [9,6,4,2,3,5,7,0,1]
??: 8
??:
???????????????????????????????

 */

// ??1?
// ?????????????

class Solution {
public:
    static bool cmp(const int&a,const int&b)
    {
        return a<b;
    }
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)
                return i;
        }
        return nums.size();
    }
};

// ??2???
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            res^=nums[i];
            res^=i;
        }
        return res;
    }
};

// ??3???????
// ????sum??num?????????????????

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=(nums.size()*(nums.size()+1))/2;
        for(int i=0;i<nums.size();i++)
        {
            sum-=nums[i];
        }
        return sum;
    }
};

// ??4?
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum-nums[i]+i;
        }
        return sum+nums.size();
    }
};
