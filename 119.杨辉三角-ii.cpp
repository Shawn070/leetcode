/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 * 
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？

 */

// normal loop
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        for (int i = 0; i < rowIndex + 1; i++) {
            vec.push_back(1);
            for (int j=i-1; j >= 1; j--) {
                vec[j] = vec[j-1] + vec[j];
            }
        }
        return vec;
    }
};

/*
Based on math, the kth element for nth row is 
C(n, k) = n! / (k!*(n-k)!), then res[k] = res[n - k]

so the relationship between res[i] and res[i-1] is 
        n! / (k!(n-k)!) 
    ——————————————————————— = (n - k + 1) / k
    n! / ((k-1)!(n-k + 1)!)
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for(int k = 1; k <= (rowIndex + 1)/2; k++)
            res[k] = res[rowIndex - k] = (long)res[k - 1]*(long)(rowIndex - k + 1)/k;
        return res;
    }
};

