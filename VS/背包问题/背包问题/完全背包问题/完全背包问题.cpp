/*
����Ϊ10�ı�������5����Ʒ��ÿ����Ʒ�������ޣ�
�������ֱ�Ϊ5��4��3��2��1��
���ֵ�ֱ�Ϊ1��2��3��4��5��
����㷨��ʵ�ֱ�������Ʒ��ֵ���

�������£����50��
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

    cout << "�ܵļ�ֵΪ: " << dp[10] << endl;
    return 0;
}
