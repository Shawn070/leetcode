#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int num;
	char ch;
	cin >> num;
	cin >> ch;
	while (num--) {
		string str;
		getline(cin, str);

		if (str.length() > 10) {
			cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl;
		}
		else {
			for (int i = 0; i < str.length(); i++)
				cout << str[i];
			cout << endl;
		}
		

	}
}