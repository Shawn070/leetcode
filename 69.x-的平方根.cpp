/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x ????

    ?? int sqrt(int x) ???

    ????? x ??????? x ??????

    ??????????????????????????????

    ?? 1:

    ??: 4
    ??: 2
    ?? 2:

    ??: 8
    ??: 2
    ??: 8 ????? 2.82842..., 
         ???????????????????

 */
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) return 0;
        if(x <= 3) return 1;
        int l = 1, r = x;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid == x / mid)
                return mid;
            else if (mid > x / mid)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return r;
    }
};

