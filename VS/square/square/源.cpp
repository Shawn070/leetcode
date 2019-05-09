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
				vec[i] = -vec[i];		//��Ƿ�������
				if (DFS(vec, curLen - abs(vec[i])))
					return true;
				vec[i] = abs(vec[i]);	//�ָ�
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
		sort(vec.begin(), vec.end());	//��������̰��ѡ�񳤵Ĺ�����
		for (int i = 1; i < 3; i++) {	//ֻ���ж��Ƿ񹹽���3����Ϊsum/4�ı߳�
			if (!s.DFS(vec, sum / 4))
				cout << "no" << endl;
		}
		cout << "yes" << endl;
	}

	return 0;
}