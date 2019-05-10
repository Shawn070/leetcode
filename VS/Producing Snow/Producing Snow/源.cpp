#include <iostream>
using namespace std;

int main() {
	int n;
	int a[110], b[110], c[110], d[110];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < n; j++)
		cin >> b[j];
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			if (a[j] > 0) {
				if (a[j] > b[i]) {
					sum  += b[i];
					a[j] -= b[i];
				}
				else {
					sum  += a[j];
					a[j] -= b[i];
				}
			}
		}
		c[i] = sum;
	}
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			cout << c[i] << endl;
		else
			cout << c[i] << " ";
	}
	return 0;
}