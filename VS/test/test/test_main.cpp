#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>	//accmulate
using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int sumFront = 0, sumBack = 0;
		for (int i = 0; i < nums.size(); i++) {
			sumFront = accumulate(nums.begin(), nums.begin() + i, 0);
			sumBack = accumulate(nums.begin() + i + 1, nums.end(), 0);
			if (sumFront == sumBack) return i;
		}
	}
};

int main() {
	vector<int> nums{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	cout << Solution().pivotIndex(nums) << endl;
	return 0;
}