/*
�������ˣ��ֵ��˽���ļ��ڡ�

������n���к�ֽ��n��Ů��ֽҪ���n�Ժ����ѡ�

ÿ���˶���һ������ֵ��ÿ��һ���к�ֽ��һ��Ů��ֽ��Ϊ�����ѣ��������ǻ�����ôһ������Σ���ô���ǲ���������ֵ������������ֵ�ĳ˻���

Ϊ���ú�ֽ�Ƕ����ҵ������ѣ���������Ҫ�������ǽ�����Ů��ԣ�Ŀ����������������������ֵ�ܺ���С��

Input
��һ��Ϊһ������n����1 <= n <= 10000��

�ڶ���Ϊn������������ֵXi��������Ϊn��Ů��������ֵYi��(1 <= Xi,Yi <= 10000)

Output
�����С������ֵ�ܺ�

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

//��һ��
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

//������
int main() {
	int n;
	while (cin >> n) {
		int *boy, *girl;
		boy = new int[n], girl = new int[n];
		for (int i = 0; i < n; i++) cin >> boy[i];
		for (int i = 0; i < n; i++) cin >> girl[i];
		sort(boy, boy + n);
		sort(girl, girl + n, greater<int>());
		long long sum = 0;	//ע����long long������int
		for (int i = 0; i < n; i++)
			sum += boy[i] * girl[i];
		cout << sum << endl;
		delete boy, girl;
	}

	return 0;
}