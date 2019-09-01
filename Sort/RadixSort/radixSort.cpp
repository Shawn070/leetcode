/*
基数排序:

时间复杂度：O(n * k)
空间复杂度：O(n + k)
稳定性：稳定

基本思想：
从低位开始，对所有数字进行排序。
第1轮排序后，数字的个位数要有序；
第2轮排序后，数字的十位数要有序，如果十位数相同的数，个位数要按照之前的相对顺序摆放；
依次类推直至最高位排序完成。

基数排序 vs 计数排序 vs 桶排序：
    基数排序：根据键值的每位数字来分配桶；
    计数排序：每个桶只存储单一键值；
    桶排序：每个桶存储一定范围的数值；
*/

#include <iostream>
using namespace std;

// 找出数组种最大位数
int maxbit(int L[], int len) {
    int max = L[0];
    for (int i = 0; i < len; i++)   //找出最大的数
        if (max < L[i])
            max = L[i];
    
    int d = 1;
    int p = 10;
    while (max >= p) {  //把最大的数除10，计算出最大位数
        max /= p;
        d++;
    }
    return d;
}

void radixSort(int* L, int len) {
    if (L == nullptr || len <= 0) return ;
    
    int d = maxbit(L, len); // 找出数组种最大位数
    int *tmp = new int[len];
    int *cnt = new int[10]; //计数器
    int radix = 1;
    int n;
    
    for (int i = 1; i <= d; i++) {  //对每一位分别进行排序
        
        for (int j = 0; j < 10; j++) cnt[j] = 0;    // 清空计数器
        
        for (int j = 0; j < len; j++) { //统计每个桶中数的个数
            n = (L[j] / radix) % 10;
            cnt[n]++;
        }

        for (int j = 1; j < 10; j++)    //没懂这步！！！
            cnt[j] += cnt[j - 1];
        
        for (int j = len - 1; j >= 0; j--) {
            n = (L[j] / radix) % 10;
            tmp[cnt[n] - 1] = L[j];
            cnt[n]--;
        }

        for (int j = 0; j < len; j++) 
            L[j] = tmp[j];
        radix *= 10;
    }
    delete []tmp;
    delete []cnt;
}

//通过二维数组的方式
void radix(int *L, int len) {
    int n;
    for (int i = 1; i <= 100; i *= 10) { //最多百位数排序，不具自适应性
        int dic[20][10] = {0};//建立一个20行，10列的数组，每一列分别代表0~9位数，20行代表能存放的总个数
        for (int j = 0; j < len; j++) {
            n = (L[j] / i) % 10;
            dic[j][n] = L[j];
        }
        int k = 0;
        for (int p = 0; p < 10; p++) {
            for (int q = 0; q < len; q++) {
                if (dic[q][p] != 0)
                    L[k++] = dic[q][p];
            }
        }
    }
}

int main() {
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    radixSort(L, len);

    for (int i = 0; i < len; i++) 
        cout << L[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}