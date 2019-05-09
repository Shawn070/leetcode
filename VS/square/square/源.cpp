#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	bool DFS(vector<int> &vec, int curLen) {
		if (curLen == 0) return true;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] > curLen) return false;
			if (vec[i] > 0) {
				vec[i] = -vec[i];		//标记访问数据
				if (DFS(vec, curLen - abs(vec[i])))
					return true;
				vec[i] = abs(vec[i]);	//恢复
			}
		}
		return false;
	}
};

int main() {
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		int num;
		int sum = 0;
		vector<int> vec;
		for (int i = 0; i < n; i++) {
			cin >> num;
			sum += num;
			vec.push_back(num);
		}

		if (n <= 3 || 0 != sum % 4) {
			cout << "no" << endl;
			continue;
		}
		Solution s;
		sort(vec.begin(), vec.end());	//升序排序，贪心选择长的构建边
		for (int i = 1; i < 3; i++) {	//只需判断是否构建出3条长为sum/4的边长
			if (!s.DFS(vec, sum / 4))
				cout << "no" << endl;
		}
		cout << "yes" << endl;
	}

	return 0;
}