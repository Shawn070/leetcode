/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题

    给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

    请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

    说明:
    不允许旋转信封。

    示例:

    输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
    输出: 3 
    解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

 */
// 
class LRUCache {
public:
	void swap(vector<int> &v, int pos) {
		int tmp = v[pos];
		v.erase(v.begin() + pos);
		v.push_back(tmp);
	}

	vector<int> LRU_k;
	vector<int> LRU_v;
	int num = 0;
	LRUCache(int capacity) {
		//vector<vector<int>> LRU(2,vector<int>(capacity));
		num = capacity;
	}

	int get(int key) {
		auto it = find(LRU_k.begin(), LRU_k.end(), key);
		if (it == LRU_k.end()) return -1;
		int pos = it - LRU_k.begin();
		int back = LRU_k.size() - 1;

		swap(LRU_k, pos);
		swap(LRU_v, pos);

		return LRU_v[back];
	}

	void put(int key, int value) {
		auto it = find(LRU_k.begin(), LRU_k.end(), key);
		if (it != LRU_k.end()) {
			int pos = it - LRU_k.begin();
			LRU_v[pos] = value;

			swap(LRU_k, pos);
			swap(LRU_v, pos);

			return;
		}

		if (LRU_k.size() == num) {
			LRU_k.erase(LRU_k.begin());
			LRU_v.erase(LRU_v.begin());
		}

		LRU_k.push_back(key);
		LRU_v.push_back(value);
	}
};

