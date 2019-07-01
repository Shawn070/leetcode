#include <iostream>

using namespace std;

int main() {
	cerr << "input n:";
	int n;
	cin >> n;
	int* dp = new int[n + 1]{0};
	int d[10];
	//memset(dp, 0, (n + 1) * 4);
	for (auto i = 0; i < 10; i++) {
		cout << dp[i] << endl;
	}
	dp[0] = 1;
	dp[1] = 1;

	return 0;
}