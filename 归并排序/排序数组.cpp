#include<iostream>
using namespace std;

void Merge(int* L, int* A, int lenA, int* B, int lenB) {
    int i = 0, j = 0, k = 0;
    while (i < lenA && j < lenB) {
        if (A[i] < B[j])
            L[k++] = A[i++];
        else
            L[k++] = B[j++];
    }
    while (i < lenA)
        L[k++] = A[i++];
    while (j < lenB)
        L[k++] = B[j++];
}

void MergeSort(int* L, int len) {
    if (len < 2)
        return ;
    // 将 L 分为 A、B 两个部分
    int mid = len / 2;
    int* A = new int[mid];
    int* B = new int[len - mid];
    for (int i = 0; i < mid; i++)
        A[i] = L[i];
    for (int j = mid; j < len; j++)
        B[j - mid] = L[j];
        
    MergeSort(A, mid);
    MergeSort(B, len - mid);
    // 将 A、B 合并排序
    Merge(L, A, mid, B, len - mid);
    delete []A;
    delete []B;
}

int main(){
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    MergeSort(L, len);

    for (auto L : L) {
        cout << L << endl;
    }
    system("PAUSE");
    return 0;
}