/*
快速排序:

最差时间复杂度：O(n^2)
最优时间复杂度：O(nlog2(2))
平均时间复杂度：O(nlog2(2))
空间复杂度：O(n)
稳定性：不稳定

基本思路：
1. 从数列中挑出一个元素，称为 “基准”（pivot）；
2. 重新排序数列，所有元素比基准值小的摆放在基准前面，
   所有元素比基准值大的摆在基准的后面（相同的数可以到任一边），
   在这个分区退出之后，该基准就处于数列的正确的位置；
3. 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
*/


#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

// 快速排序（递归）
void QSort(vector<int> &v, int low, int high) {
    if (low >= high)    // 结束标志
        return ;
    int first = low;
    int last = high;
    int key = v[first];
    
    while (first < last) {
        // 将比第一个小的移到前面
        while (first < last && v[last] >= key)
            last--;
        if (first < last) 
            v[first++] = v[last];

        // 将比第一个大的移到后面
        while (first < last && v[first] <= key) 
            first++;
        if (first < last)
            v[last--] = v[first];
    }
    // 基准置位
    v[first] = key;
    QSort(v, low, first - 1);   // 前半递归
    QSort(v, first + 1, high);  // 后半递归
}

int main(){
    vector<int> v({5, 1, 9, 3, 7, 4, 8, 6, 2});
    QSort(v, 0, v.size() - 1);
    for (auto n : v) {
        cout << n << ' ';
    }
    cout << endl;
    system("PAUSE");
    return 0;
}