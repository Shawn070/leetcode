/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

 */

/*动态规划:
时间复杂度O(nlogn)，空间复杂度O(n)

定义一个函数f(n)表示我们要求的解。f(n)的求解过程为：
f(n) = 1 + min{
  f(n-1^2), f(n-2^2), f(n-3^2), f(n-4^2), ... , f(n-k^2) //(k为满足k^2<=n的最大的k)
}
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n+1, 0);
        for (int i = 1; i <= n; i++) {
            int minVal = INT_MAX;
            for (int j = 1; j*j <= i; j++) 
                minVal = min(minVal, f[i - j*j]);
            f[i] = minVal + 1;
        }
        return f[n];
    }
};

//方法二：BFS(广度优先遍历)
class Solution {
public:
    int numSquares(int n) {
        //int: 当前数；int：当前步数
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        vector<bool> visited(n + 1, false); //记录访问过的数
        visited[n] = true;
        while (!q.empty()) {
            //获取 q.front()
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            for (int i = 0; i * i <= num; i++) {
                int a = num - i * i;    //减去平方数，获得下一个图节点位置，即是step + 1层。可能有多种情况，会到达多个节点。
                if (a < 0) break;
                if (a == 0) return step + 1;    //当到达0节点，说明已经走完了。由于是层序的，第一个到达0节点就直接返回步数了。
                if (!visited[a])
                    q.push(make_pair(a, step + 1)); //记录到达当前节点，已经走了的步数。
                visited[a] = true;
            }
        }
        return 0;
    }
};


