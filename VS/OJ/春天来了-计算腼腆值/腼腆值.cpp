/*
春天来了！又到了交配的季节。

这里有n个男孩纸和n个女孩纸要组成n对好朋友。

每个人都有一个腼腆值，每当一个男孩纸和一个女孩纸成为好朋友，他们总是会有那么一点点尴尬，那么他们产生的尴尬值就是他们腼腆值的乘积。

为了让孩纸们都能找到好朋友，我们现在要帮助他们进行男女配对，目标是让他们所产生的尴尬值总和最小。

Input
第一行为一个整数n，（1 <= n <= 10000）

第二行为n个男生的腼腆值Xi，第三行为n个女生的腼腆值Yi，(1 <= Xi,Yi <= 10000)

Output
输出最小的尴尬值总和

Sample Input
2
1 2
2 1
Sample Output
4
*/

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <functional> //greater<int>
using namespace std;

//法一：
int main() {
	int n, n1, n2, num1, num2;
	while (cin >> n){
		n1 = n2 = n;
		vector<int> vec1, vec2;
		while (n1--) {
			cin >> num1;
			vec1.push_back(num1);
		}
		while (n2--) {
			cin >> num2;
			vec2.push_back(num2);
		}
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += vec1[i] * vec2[n - i - 1];
		}
		cout << ans << endl;
	}
	
	return 0;
}

//法二：
int main() {
	int n;
	while (cin >> n) {
		int *boy, *girl;
		boy = new int[n], girl = new int[n];
		for (int i = 0; i < n; i++) cin >> boy[i];
		for (int i = 0; i < n; i++) cin >> girl[i];
		sort(boy, boy + n);
		sort(girl, girl + n, greater<int>());
		long long sum = 0;	//注意是long long，不是int
		for (int i = 0; i < n; i++)
			sum += boy[i] * girl[i];
		cout << sum << endl;
		delete boy, girl;
	}

	return 0;
}