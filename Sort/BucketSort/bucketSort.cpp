/*
桶排序:

最差时间复杂度：O(n^2)
最优时间复杂度：O(n)
平均时间复杂度：O(n + k)
空间复杂度：O(n + k)
稳定性：稳定

基本思想：
1. 设置一个定量的数组当作空桶子;
2. 寻访序列，并且把数据一个一个放到对应的桶子去;
3. 对每个不是空的桶子进行排序;
4. 从不是空的桶子里把项目再放回原来的序列中。
*/

#include <iostream>
#include <vector>
#include <list>
#include <memory.h>
using namespace std;

//将数插入到排序链表
void insert(list<int>& bucket, int val) {
    auto iter = bucket.begin();
    while (iter != bucket.end() && val >= *iter)
        ++iter;
    //insert会在iter之前插入数据，这样可以稳定排序
    bucket.insert(iter, val);
}

void bucketSort(int* L, int len) {
    if (L == nullptr || len <= 0) return ;
    
    // 找出最小、最大数
    int min = L[0], max = min;
    for (int i = 1; i < len; i++) {
        if (min > L[i]) min = L[i];
        if (max < L[i]) max = L[i];
    } 

    int k = 10; // k为数字间的间隔
    //向上取整，例如[0,9]有10个数，(9 - 0)/k + 1 = 1;
    int bucketsNum = (max - min) / k + 1;   // 多1是数组的0下标
    vector<list<int>> buckets(bucketsNum);
    for (int i = 0; i < len; i++) {
        int val = L[i];
        //(value-min)/k就是在哪个桶里面
        insert(buckets[(val - min) / k], val);
    }
    
    // 将桶中的数依次取出放入原数组L
    int idx = 0;
    for (int i = 0; i < bucketsNum; i++) {
        if (buckets[i].size()) {
            for (auto & val : buckets[i]) 
                L[idx++] = val;
        }
    }
}

int main() {
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    bucketSort(L, len);

    for (int i = 0; i < len; i++) 
        cout << L[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}