#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int sum = 13, t = 0, cnt = 3;
		while (sum + t < n) {
			sum += t;
			t = sum;
			sum = 2 * t + 1;
			cnt++;
		}
		if (n == 1) cout << 1 << endl;
		else if (n <= 4) cout << 2 << endl;
		else if (n <= 13) cout << 3 << endl;
		else cout << cnt << endl;
	}
	return 0;
}