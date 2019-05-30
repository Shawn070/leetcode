#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>	//accmulate
#include <functional> //greater
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.length() < b.length())
			swap(a, b);
		int i = a.length(), j = b.length();
		while (i--) {
			if (j) 
				a[i] += b[--j] & 1;
				//µÈÓÚ a[i] += b[--j] - '0';
			if (a[i] > '1') {
				a[i] -= 2;
				if (i) a[i - 1]++; else a = '1' + a;
			}
		}
		return a;
	}
};

int main() {
	string a("1010");
	string b("1011");
	cout << Solution().addBinary(a, b) << endl;
	return 0;
}