/*
һ������n (n > 4 ) �����һ�����������Ļ�,���ҽ���n - 4 �� n + 4 ��������
�������ܼ򵥣���һ��N������һ�����ĳ�������n����n <= N

Input
һ������N (4 < N < 10^9),���������ж���

Output
���û����������������n���-1���������n

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