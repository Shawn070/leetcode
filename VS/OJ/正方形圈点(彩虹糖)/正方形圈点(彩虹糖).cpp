/*
�������Ǽ���MZ��ϲ���Բʺ��ǵģ��ٺٺ١�Ϊ�˻�ȡ������ʺ��ǣ�MZ��������һ�����⣺

ƽ���Ϸ���N�Ųʺ��ǣ�ÿ�Ųʺ��Ƕ���һ������X��Y��MZ��Ҫ��һ��ƽ�����������������ȥ����Щ�ʺ��Ǹ���Χ��������ô��Щ�ʺ��Ƕ���������   ~\(�R���Q)/~������

�������������С����Ƕ��٣�

MZ�ǳ���Բʺ��ǣ���������

Input
��һ��ΪN����ʾ�ʺ��ǵ���Ŀ

����N�У�ÿ��������Xi��Yi����ÿ�Ųʺ��ǵĺ�������

2 <= N <= 1000

0 <= Xi��Yi<= 100000

Output
������������С���

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