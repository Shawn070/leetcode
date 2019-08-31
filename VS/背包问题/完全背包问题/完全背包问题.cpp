/*
容量为10的背包，有5种物品，每种物品数量无限，
其重量分别为5，4，3，2，1，
其价值分别为1，2，3，4，5。
设计算法，实现背包内物品价值最大。

代码如下（输出50）
*/

#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    int total_weight = 10;
    int w[6] = { 0,5,4,3,2,1 };
    int v[6] = { 0,1,2,3,4,5 };
    int dp[11] = { 0 };

    for (int i = 1; i <= 5; i++)
        for (int j = w[i]; j <= 10; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

    cout << "总的价值为: " << dp[10] << endl;
    return 0;
}
