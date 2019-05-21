/*
一个素数n (n > 4 ) 如果是一个超级素数的话,当且仅当n - 4 和 n + 4 都是素数
你的任务很简单：给一个N，发现一个最大的超级素数n满足n <= N

Input
一个整数N (4 < N < 10^9),输入数据有多组

Output
如果没有满足条件的整数n输出-1，否则输出n

Sample Input
8
Sample Output
7
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n >= 7) cout << 7 << endl;
		else cout << -1 << endl;
	}
	return 0;
}

//int main() {
//	long long n;
//	while (cin >> n) {
//		bool flag = true;
//		if (n <= 4) {
//			cout << "-1" << endl;
//			continue;
//		}
//		while (n) {
//			if (n <= 4) {
//				cout << "-1" << endl;
//				break;
//			}
//			for (int i = 2; i < n; i++) {
//				if (n % i == 0) {
//					flag = false;
//					break;
//				}
//			}
//			if (flag) {
//				for (int i = 2; i < n - 4; i++) {
//					if ((n - 4) % i == 0) {
//						flag = false;
//						break;
//					}
//				}
//			}
//			if (flag) {
//				for (int i = 2; i < n + 4; i++) {
//					if ((n + 4) % i == 0) {
//						flag = false;
//						break;
//					}
//				}
//			}
//			if (flag) {
//				cout << n << endl;
//				break;
//			}
//			flag = true;
//			--n;
//		}
//	}
//	return 0;
//}