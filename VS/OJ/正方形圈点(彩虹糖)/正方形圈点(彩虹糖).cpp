/*
于是我们假设MZ是喜欢吃彩虹糖的，嘿嘿嘿。为了获取到更多彩虹糖，MZ遇到这样一个问题：

平面上放着N颗彩虹糖，每颗彩虹糖都有一个坐标X、Y。MZ需要拿一个平行于坐标轴的正方形去把这些彩虹糖给包围起来，那么这些彩虹糖都会属于他   ~\(≧▽≦)/~啦啦啦

问这个正方形最小面积是多少？

MZ非常想吃彩虹糖，请你帮帮他

Input
第一行为N，表示彩虹糖的数目

下面N行，每行两个数Xi、Yi代表每颗彩虹糖的横纵坐标

2 <= N <= 1000

0 <= Xi、Yi<= 100000

Output
正方形所需最小面积

Sample Input
2
0 0
2 2
Sample Output
4
*/

#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int n;
	long long c;
	long long a[1001], b[1001];
	long long max1, min1, max2, min2;
	max1 = 0, max2 = 0;
	min1 = 100000, min2 = 100000;
	cin >> n;
		
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] > max1)
			max1 = a[i];
		if (a[i] < min1)
			min1 = a[i];
		if (b[i] > max2)
			max2 = b[i];
		if (b[i] < min2)
			min2 = b[i];
	}
	c = max((max1 - min1), (max2 - min2));
	cout << c * c << endl;
	return 0;
}