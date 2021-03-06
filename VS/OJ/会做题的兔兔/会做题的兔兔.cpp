/*
大家都听说梅小姐喂养了很多兔兔。梅小姐的兔兔超级萌、超级听话，经常能帮助梅小姐AC题目。

有一天，梅小姐给兔兔们一个数字，然后命令兔兔们去寻找有多少个不同的集合满足集合内的元素相加等于这个数字，并且兔兔们找的每个数都只能是2的k次幂。

比如： 梅小姐给了一个7：

1) 1+1+1+1+1+1+1
2) 1+1+1+1+1+2
3) 1+1+1+2+2
4) 1+1+1+4
5) 1+2+2+2
6) 1+2+4

兔兔们就寻找出这6种情况。

作为萌萌哒的你，也想能拥有兔兔一样的能力，

于是梅小姐给你一个数n，你要马上回答出有多少种情况满足条件？

Input
每行一个整数N，1 <= N <= 1000000  代表梅小姐给你的数

Output
每行输出一个整数，即方案数。因为答案太大，故答案mod 1000000007

Sample Input
7
Sample Output
6
*/

#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int dp[1111111];
int mod = 1000000007;

int main() {
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (i % 2)
			dp[i] = dp[i - 1] % mod;
		else
			dp[i] = (dp[i / 2] + dp[i - 1]) % mod;
	}
	int digit;
	while (scanf("%d", &digit) != EOF)printf("%d\n", dp[digit]);

	return 0;
}
