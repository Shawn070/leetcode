#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>	//accmulate
#include <functional> //greater
using namespace std;

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		vector<int> temp = nums;
		sort(temp.begin(), temp.end(), greater<int>());
		if (temp[0] >= temp[1] * 2) {
			auto it = find(nums.begin(), nums.end(), temp[0]);
			return distance(nums.begin(), it);
		}
		return -1;
	}
};

int main() {
	vector<int> nums{ 0,0,0,1 };
	cout << Solution().dominantIndex(nums) << endl;
	return 0;
}