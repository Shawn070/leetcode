#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		vector<string> val;
		stack<long> s;
		int n1, n2;
		int tmp;
		string st;
		for (string str : tokens) {
			if (str == "+" || str == "-" || str == "*" || str == "/") {
				n1 = s.top();
				s.pop();
				n2 = s.top();
				s.pop();
				tmp = calc(n1, n2, str);
				s.push(tmp);
			}
			else {
				s.push(atoi(str.c_str()));
			}
		}
		return s.top();
	}
	int calc(int n1, int n2, string operation) {
		switch (operation[0])
		{
		case '+':
			return n1 + n2;
			break;
		case '-':
			return n2 - n1;
			break;
		case '*':
			return n1 * n2;
			break;
		case '/':
			return n2 / n1;
			break;
		}
		return -1;
	}
};

void main() {
	vector<string> tokens({"2", "1", "+", "3", "*"});
	Solution s;
	int val = s.evalRPN(tokens);
	cout << val << endl;

}