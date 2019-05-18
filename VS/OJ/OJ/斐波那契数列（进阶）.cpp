#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	if (N < 1 || N > 1298777728820984005) {
		cout << "False" << endl;
		return 0;	
	}
	if (N == 1) {
		cout << "True" << endl;
		return 0;
	}
	long long n1 = 1, n2 = 1;
	for (int i = 2; i <= 100; i++) {
		n1 += n2;
		swap(n1, n2);
		if (N == n2) {
			cout << "True" << endl;
			return 0;
		} 
	}
	cout << "False" << endl;
	return 0;
}