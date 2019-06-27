/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] ???
 * 
??????????? n ?????????

?????? 1 ? 2 ??????????????????????

????? n ???????

?? 1?

??? 2
??? 2
??? ????????????
1.  1 ? + 1 ?
2.  2 ?
?? 2?

??? 3
??? 3
??? ????????????
1.  1 ? + 1 ? + 1 ?
2.  1 ? + 2 ?
3.  2 ? + 1 ?

 */

// ???
/*
This problem is a Fibonacci problem. 
F(n)=F(n-1)+F(n-2); Solving this problem 
by recursion ,we will do a lot of same recursion. 
Example: F(10)=F(9)+F(8); F(9)=F(8)+F(7); 
we calculate F(8) twice,when n is large,this 
will increase as a rate of n’s exponent.

So a more efficient way to solve this problem 
is from Bottom to Top. Calculate F(0) ,F(1);
 then F(2)…
*/
//?????
class Solution {
public:
    int climbStairs(int n) {
        if (1 == n) return 1;
        int stepOne = 1;
        int stepTwo = 0;
        int ret = 0;
        for (int i=1; i <= n; i++) {
            ret = stepOne + stepTwo;
            stepTwo = stepOne;
            stepOne = ret;
        }
        return ret;
    }
};

//????:(4 ms	8.3 MB)
class Solution {
public:
    int climbStairs(int n) {
        if (1 == n) return 1;
        int *dp = new int[n + 1]();
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


//??
class Solution {
public:
    int climbStairs(int n) {
        return helper(0, n);
    }
    
    int helper(int i, int n) {
        if (i > n) return 0;
        if (i == n) return 1;
        return helper(i + 1, n) + helper(i + 2, n);
    }
};

//?? + ????0 ms	8.2 MB?
class Solution {
public:
    int climbStairs(int n) {
        // int memo[n + 1]={};  //0ms
        int *memo = new int[n + 1]();   //4ms
        return helper(0, memo, n);
    }
    
    int helper(int i, int *memo, int n) {
        if (i > n) return 0;
        if (i == n) return 1;
        if (memo[i] > 0) return memo[i];
        memo[i] = helper(i + 1, memo, n) + helper(i + 2, memo, n);
        return memo[i];
    }
};



