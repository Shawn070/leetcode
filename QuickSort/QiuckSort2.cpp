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