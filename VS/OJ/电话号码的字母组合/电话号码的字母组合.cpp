#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string num;
	cin >> num;
	vector<string> res;
	res.push_back("");
	string charMap[10] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	for (int i = 0; i < num.length(); i++) {
		string chars = charMap[num[i] - '0'];
		vector<string> tmp;
		/*for (auto m : res) {
		for (auto n : chars) {
		tmp.push_back(m + n);
		}
		}*/
		for (auto m : chars) {
			for (auto n : res) {
				tmp.push_back(n + m);
			}
		}
		res = tmp;
	}

	for (auto r : res)
		cout << r << endl;

	return 0;
}