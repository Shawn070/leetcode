#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

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


int main() {
	LRUCache lru(2);
	lru.get(2);
	lru.put(2, 6);
	lru.put(1, 5);
	lru.get(1);
	lru.get(2);
	return 0;
}