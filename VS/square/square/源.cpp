#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>
#include<functional>
using namespace std;


bool DFS(vector<int> &vec, int curLen) {
	if (curLen == 0) return true;			// ----------
	for (int i = 0; i < vec.size(); i++) {	//			|
		if (vec[i] > curLen) return false;	//			|
		if (vec[i] > 0) {					//			|
			vec[i] = -vec[i];		//��Ƿ�������		|
			if (DFS(vec, curLen - abs(vec[i])))	//	<----	
				return true;		//���ڷ��� true������������ ÿ������Ӧ����
			vec[i] = abs(vec[i]);	//�������� �ָ�
		}
	}
	return false;
}

bool makesquare(vector<int>& nums) {
	if (nums.size() < 4) return false;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 4) return false;                          //������Ϊ��һ�����ܹ���

	sort(nums.begin(), nums.end(), greater<int>());     //��������̰��ѡ�񳤵Ĺ�����
	for (int i = 0; i<3; ++i) {                         //ֻ���ж��Ƿ񹹽���3����Ϊsum/4�ı߳�
		if (!DFS(nums, sum / 4))  return false;			//�����ҳ�3����Ϊsum/4�ıߣ��ҹ��������Ϊ����
	}
	return true;
}


int main() {
	int m;
	cin >> m;
	vector<string> str;
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

		sort(vec.begin(), vec.end());	//��������̰��ѡ�񳤵Ĺ�����
		if (makesquare(vec))
			//str.push_back("yes");
			cout << "yes" << endl;
		else
			cout << "no" << endl;
			//str.push_back("no");
	}
	/*for (int i = 0; i < str.size(); i++)
		cout << str[i] << endl;*/
	return 0;
}