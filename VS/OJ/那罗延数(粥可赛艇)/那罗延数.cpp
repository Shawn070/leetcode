/*
1.那罗延数N(n,k)的计算公式：

N(n,k) = 1/n * C(n,k) * C(n,k-1)

2.那罗延三角前八项：

k =      1   2   3   4   5   6   7   8
n = 1    1
	2    1   1
	3    1   3   1
	4    1   6   6   1
	5    1  10  20  10   1
	6    1  15  50  50  15   1
	7    1  21 105 175 105  21   1
	8    1  28 196 490 490 196  28   1

3.应用：

在由n对"("和")"组成的字符串中，共有k对"("与")"相邻,
这样的字符串一共有N(n,k)个。例如n=4,k=2时，N(n,k)=6


4.性质：

那罗延三角中每一行的和为卡特兰数，即
N(n,1) + N(n,2) + N(n,3) + ... + N(n,n) = Catalan(n)
*/

#include <iostream>
using namespace std;
int main(void) {
	int t, n, k;
	long long C[21][21];
	C[0][0] = C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= 20; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << C[n][k] * C[n][k - 1] / n << endl;
	}
	return 0;
}