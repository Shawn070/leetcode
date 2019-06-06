/*
1000
200 600 100 180 300 450
6 10 3 4 5 8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <functional>

#pragma warning(disable : 4996)

#define ARRAY_MAX 101
#define ROW_MAX 1001

// Welcome to vivo !

int findBest(int prices[], int vals[], int len, int total)
{
	//TODO write your code here
	using namespace std;
	std::multimap<float, int, greater<float>> M;
	for (int i = 0; i < len; i++) {
		M.insert(pair<float, int>(float(vals[i]) / float(prices[i]), prices[i]));
	}
	int res = 0;
	for (auto m : M) {
		if (total / m.second != 0) {
			total -= m.second;
			res += int(m.first * float(m.second));
		}
	}
	return res;
}

int main(void)
{
	int total = 0, vMax = 0, index = 0, i = 0;
	int prices[ARRAY_MAX] = { 0 };
	int vals[ARRAY_MAX] = { 0 };


	scanf("%d", &total);

	do {
		scanf("%d", &prices[index++]);
	} while (getchar() != '\n');

	do {
		scanf("%d", &vals[i++]);
	} while (getchar() != '\n');

	vMax = findBest(prices, vals, index, total);
	printf("%d", vMax);
}