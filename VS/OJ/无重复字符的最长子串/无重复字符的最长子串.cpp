#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> dict(256, -1);
		//memset(dict, -1, 256);
		int maxLen = 0, start = -1;
		for (int i = 0; i < s.length(); i++) {
			if (dict[s[i]] > start)
				start = dict[s[i]];
			dict[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}
		return maxLen;
	}
};



int main() {
	char c[256];
	while (cin.getline(c, 256)) {
		string s(c);
		Solution S;
		cout << S.lengthOfLongestSubstring(s) << endl;
	}
	
	return 0;
}