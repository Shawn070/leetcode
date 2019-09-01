/*
计数排序:

时间复杂度：O(n + K)
空间复杂度：O(n + K)
稳定性：稳定

基本思想：
1. 假设数据在[min,max]之间均匀分布；
2. 那么将区间[min,max]等分成n份，这n个区间便称为n个桶；
3. 将数据加入对应的桶中，然后每个桶内单独排序；
4. 由于桶之间有大小关系，因此可以从大到小(或从小到大)将桶中元素放入到数组中。
*/

#include <iostream>
#include <memory.h>
using namespace std;

void countSort(int* L, int len) {
    if (L == nullptr || len <= 0)
        return ;
    
    // 找出最大数
    int maxL = L[0];
    for (int i = 1; i < len; i++) {
        if (L[i] > maxL)
            maxL = L[i];
    } 

    // 定义并初始化数组
    int* countL = new int[maxL + 1];
    memset(countL, 0, sizeof(countL[0])*(maxL + 1));
    // for (int i = 0; i <= maxL; i++)
    //     countL[i] = 0;
    // 遍历数组，统计每个数出现的次数
    for (int i = 0; i < len; i++)
        ++countL[L[i]];
    
    // 排序数组，某个数出现了几次，便在 L 种累计输出几次
    int idx = 0;
    for (int i = 0; i <= maxL; i++)
        for (int j = 0; j < countL[i]; j++) 
            L[idx++] = i;
    
    delete []countL;
}

int main() {
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    countSort(L, len);

    for (int i = 0; i < len; i++) 
        cout << L[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}