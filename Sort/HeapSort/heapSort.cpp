/*
堆排序:

时间复杂度：O(nlog2(n))
空间复杂度：O(1)
稳定性：不稳定
*/

#include <iostream>
using namespace std;

// 递归方式构建大根堆(len是L的长度，idx是第一个非叶子节点的下标)
void adjust(int* L, int len, int idx) {
    int l = 2 * idx + 1;    // idx的左子节点
    int r = 2 * idx + 2;    // idx的右子节点

    int maxIdx = idx;

    if (l < len && L[l] > L[maxIdx]) maxIdx = l;
    if (r < len && L[r] > L[maxIdx]) maxIdx = r;

    if (maxIdx != idx) {
        swap(L[maxIdx], L[idx]);
        adjust(L, len, maxIdx);
    }
}

void heapSort(int* L, int len) {
    // 构建大顶堆（从最后一个非叶子节点向上）
    for (int i = len / 2 - 1; i >= 0; i--)
        adjust(L, len, i);
    
    // 调整大顶堆
    for (int i = len - 1; i >= 1; i--) {
        swap(L[0], L[i]);   // 将堆顶元素与数组尾元素交换
        adjust(L, i, 0);    // 调整大顶堆
    }
}

int main() {
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    heapSort(L, len);

    for (int i = 0; i < len; i++) 
        cout << L[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}