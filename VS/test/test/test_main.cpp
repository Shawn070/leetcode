#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1, level = 0, water = 0;
		while (l < r) {
			int lower = height[l] < height[r] ? height[l++] : height[r--]; //取小数
			level = max(level, lower);	//取大数
			water += level - lower;
		}
		return water;
	}
};

int main() {
	vector<int> nums{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	Solution().trap(nums);
	return 0;
}