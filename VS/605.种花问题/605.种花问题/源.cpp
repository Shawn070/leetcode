#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		vector<int> tmp = flowerbed;
		tmp.insert(tmp.begin(), 0);
		tmp.push_back(0);
		for (int i = 1; i < tmp.size() - 1; i++) {
			if (tmp[i - 1] == 0 && tmp[i] == 0 && tmp[i + 1] == 0) {
				tmp[i] = 1;
				n--;
			}
		}
		if (n <= 0)
			return true;
		else
			return false;
	}
};


int main() {
	string str;
	getline(cin, str);
	vector<int> flowerbed;
	int j = 0;
	for (; j < str.length(); j++) {
		if (str[j] == ']')
			break;
		int num = str[j] - '0';
		if (num == 0 || num == 1) {
			flowerbed.push_back(num);
		}
	}
	int n = stoi(&str[j + 2]);
	//int n = str[j + 2] - '0';

	vector<int> tmp = flowerbed;
	tmp.insert(tmp.begin(), 0);
	tmp.push_back(0);
	for (int i = 1; i < tmp.size() - 1; i++) {
		if (tmp[i - 1] == 0 && tmp[i] == 0 && tmp[i + 1] == 0) {
			tmp[i] = 1;
			n--;
		}
	}
	if (n <= 0)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}