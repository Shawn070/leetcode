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
			vec[i] = -vec[i];		//标记访问数据		|
			if (DFS(vec, curLen - abs(vec[i])))	//	<----	
				return true;		//存在返回 true，若果存在则 每个数都应用上
			vec[i] = abs(vec[i]);	//不存在则 恢复
		}
	}
	return false;
}

bool makesquare(vector<int>& nums) {
	if (nums.size() < 4) return false;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 4) return false;                          //余数不为零一定不能构成

	sort(nums.begin(), nums.end(), greater<int>());     //升序排序，贪心选择长的构建边
	for (int i = 0; i<3; ++i) {                         //只需判断是否构建出3条长为sum/4的边长
		if (!DFS(nums, sum / 4))  return false;			//依次找出3条长为sum/4的边，找过的数标记为负数
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

		sort(vec.begin(), vec.end());	//升序排序，贪心选择长的构建边
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