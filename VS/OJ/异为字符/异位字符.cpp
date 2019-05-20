#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int main() {
	//通过strtok实现
	char chars[100];
	cin.getline(chars, 100);
	string str2;
	cin >> str2;
	char* str1;
	str1 = strtok(chars, " ,.!");
	while (str1 != NULL) {
		if (strlen(str1) == str2.length()) {
			int cnt = 0;
			for (int i = 0; i < str2.length(); i++) {
				if (str1[i] == str2[i]) {
					cnt++;
				}
			}
			if (cnt + 1 == str2.length()) {
				cout << "True" << endl;
				return 0;
			}
		}
		str1 = strtok(NULL, " ,.!");
	}
	cout << "False" << endl;
	return 0;

	//通过istringstream实现
	/*string str1, str2;
	getline(cin, str1);
	cin >> str2;
	string substr;
	istringstream is(str1);
	while (is >> substr) {
		if (substr.length() == str2.length()) {
			int cnt = 0;
			for (int i = 0; i < str2.length(); i++) {
				if (substr[i] == str2[i]) {
					cnt++;
				}
			}
			if (cnt + 1 == str2.length()) {
				cout << "True" << endl;
				return 0;
			}
		}
	}
	cout << "False" << endl;
	return 0;*/
}