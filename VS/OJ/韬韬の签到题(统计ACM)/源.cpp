//#include <iostream>
//
//using namespace std;
//
//bool is36(int num) {
//	if (num % 36) return false;
//	int tmp = num;
//	int f3 = 0, f6 = 0, f36 = 0;
//	while (tmp) {
//		if (tmp % 10 == 6) {
//			f6++;
//			if (tmp % 100 == 36)
//				f36++;
//		}
//		else if (tmp % 10 == 3)
//			f3++;
//		tmp /= 10;
//	}
//	if (f3 == f6 && f6 == f36 && f36 > 0) return true;
//	return false;
//
//}
//
//int main() {
//	int n, l;
//	bool findFlag = false;
//	cin >> n;
//	while (n--) {
//		cin >> l;
//		for (int i = l; i <= 100000; i++) {
//			if (is36(i)) {
//				cout << i << endl;
//				findFlag = true;
//				break;
//			}
//		}
//		if (!findFlag) cout << -1 << endl;
//		findFlag = false;
//	}
//	return 0;
//}


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool f36(int x) {
	if (x % 36 != 0) return false;
	string s = to_string(x);
	int len = s.size();
	bool exist = false;
	for (int i = 0; i < len; i++) {
		if (s[i] == '3' && s[i + 1] == '6') exist = true;
		if (s[i] == '3' && s[i + 1] != '6') return false;
		if (s[i] == '6' && s[i - 1] != '3') return false;
	}
	return exist;
}

int main() {
	vector<int> vec;
	for (int i = 36; i <= 100000; i++) 
		if (f36(i)) vec.push_back(i);
	int n, num;
	cin >> n;
	while (n--) {
		cin >> num;
		auto iter = lower_bound(vec.begin(), vec.end(), num);
		if (iter == vec.end()) cout << -1 << endl;
		else cout << *iter << endl;
	}
	return 0;
}