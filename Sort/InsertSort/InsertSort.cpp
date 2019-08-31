/*
直接插入排序

最差时间复杂度：O(n^2)
最优时间复杂度：O(n)
平均时间复杂度：O(n^2)
稳定性：稳定

一般步骤：
1.从第一个元素开始，该元素可以认为已被排序；
2.取出下一个元素，在已经排序的元素序列中从后向前扫描；
3.如果该元素（已排序）大于新元素，将该元素移到下一个位置；
4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
5.将新元素插入到该位置后，重复2~5
*/

#include <iostream>
using namespace std;

void insertSort(int* L, int len) {
    for (int i = 1; i < len; i++) {
        int key = L[i];
        int j = i - 1;
        while (j >= 0 && L[j] > key) {
            L[j + 1] = L[j];
            j--;
        }
        L[j + 1] = key;
    }
}

int main() {
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    insertSort(L, len);

    for (int i = 0; i < len; i++) 
        cout << L[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}