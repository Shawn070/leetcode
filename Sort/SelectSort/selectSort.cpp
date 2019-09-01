/*
选择排序:

最差时间复杂度：O(n^2)
最优时间复杂度：O(n^2)
平均时间复杂度：O(n^2)
空间复杂度：：O(1)
稳定性：不稳定

思想：
每一趟从待排序的记录中选出最小的元素，顺序放在已排好序的序列最后，直到全部记录排序完毕。
*/

#include <iostream>
using namespace std;

/*
void selectSort(int* L, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (L[j] < L[i])
                swap(L[i], L[j]);
        }
    }
}
*/

void selectSort(int* L, int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (L[j] < L[min])
                min = j;
        }
        swap(L[i], L[min]);
    }
}

int main() {
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    selectSort(L, len);

    for (int i = 0; i < len; i++) 
        cout << L[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}