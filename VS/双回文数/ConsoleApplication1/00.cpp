#include <iostream>
#include <vector>
#include <string>
using namespace std;

void main() {
	string str;
	while (getline(cin, str)) {
		if (str.length() % 2 != 0) {
			cout<<"false"<<endl;
			continue;
		}
		vector<char> res;
		int j = str.length() - 1;
		for (int i = 0; i < str.length();) {
			if (str[i] == str[i + 1] && str[j] == str[j - 1] && str[i] == str[j]) {
				res.push_back(str[i]);
				i += 2;
				j -= 2;
			}
			else
			{
				break;
			}
		}
		if (j != -1) {
			cout << "false" << endl;
		}
		for (int m = 0; m < res.size(); m++) {
			cout << res[m];
		}
		cout << endl;
	}
	return ;
}