/*
希尔排序,又称为缩小增量排序
参考链接：https://blog.csdn.net/huangyimo/article/details/80888999

平均时间复杂度：O(nlogn)
稳定性：不稳定

希尔排序是基于插入排序的以下两点性质而提出改进方法的:
1.插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率；
2.但插入排序一般来说是低效的， 因为插入排序每次只能将数据移动一位。

一般步骤为：
1.先取一个小于n的整数d1作为第一个增量，把文件的全部记录分成d1个组。
  所有距离为dl的倍数的记录放在同一个组中，在各组内进行直接插人排序。
  {8, 6, 7, 9, 1, 3, 2, 5, 4} --d=3--> {8,..., 1} {6,..., 3} {7,..., 2} {9,..., 5} 
  
2.取第二个增量d2<d1重复上述的分组和排序，直至所取的增量dt=1(dt<dt-l<…<d2<d1)，
  即所有记录放在同一组中进行直接插入排序为止。
  步长的选择是希尔排序的重要部分。只要最终步长为1任何步长串行都可以工作。
  算法最开始以一定的步长进行排序。然后会继续以一定步长进行排序，最终算法以步长为1进行排序。
  当步长为1时，算法变为插入排序，这就保证了数据一定会被排序。
*/

#include <iostream>
using namespace std;

void shelltSort(int* L, int len) {
    int gap = len / 3 + 1;
    while (gap) {
        for (int i = gap; i < len; i++) {
            int key = L[i];
            int j = i - gap;
            while (j >= 0 && L[j] > key) {
                L[j + gap] = L[j];
                j = j - gap;
            }
            L[j + gap] = key;
        }
        gap = gap / 3;
    }
}

int main() {
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    shelltSort(L, len);

    for (int i = 0; i < len; i++) 
        cout << L[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}