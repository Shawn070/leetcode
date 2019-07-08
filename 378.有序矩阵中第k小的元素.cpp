/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素

给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

示例:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
说明: 
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。

 */

// 二分法：（60 ms	11.7 MB）
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], h = matrix[n - 1][n - 1];
        while (l < h) {
            int mid = l + (h - l) / 2;
            int count = 0, j = matrix[0].size() - 1;
            for (int i = 0; i < matrix.size(); i++) {
                while (j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            if (count < k)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};

