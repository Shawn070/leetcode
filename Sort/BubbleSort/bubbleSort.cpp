/*
冒泡排序:

最差时间复杂度：O(n^2)
最优时间复杂度：O(n)
平均时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：稳定
*/

#include <iostream>
using namespace std;

void bubbleSort(int* L, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (L[j] > L[j + 1])
                swap(L[j], L[j + 1]);
        }
    }
}

int main() {
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    bubbleSort(L, len);

    for (int i = 0; i < len; i++) 
        cout << L[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}