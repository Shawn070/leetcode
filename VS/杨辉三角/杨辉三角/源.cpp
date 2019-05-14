#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		vec.push_back(1);
		for (int j = i - 1; j >= 1; j--) {
			vec[j] = vec[j - 1] + vec[j];
		}
		for (int m = 0; m < vec.size(); m++) {
			cout << vec[m];
			if (m != vec.size() - 1)
				cout << ' ';
		}
		if (i != n-1)
			cout << endl;
	}
	return 0;
}