/*
쳲��������ж���ΪF(0)=1��F(1)=1��F(n)=F(n-1)+F(n-2)��

����N�������Ӧ��F(N)��
*/

#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	if (N < 2) {
		cout << 1 << endl;
		return 0;
	}
	long long n1 = 1, n2 = 1;
	for (int i = 2; i <= N; i++) {
		n1 += n2;
		swap(n1, n2);
	}
	cout << n2 << endl;
	return 0;
}