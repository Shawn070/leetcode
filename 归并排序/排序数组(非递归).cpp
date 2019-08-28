#include<iostream>

using namespace std;

void Merge(int* L, int l, int m, int h) {
    int i = l, j = m + 1, k = 0;
    int* temp = new int[h - l + 1];
    while (i <= m && j <= h) {
        if (L[i] < L[j]) 
            temp[k++] = L[i++];
        else
            temp[k++] = L[j++];
    }
    while (i <= m) 
        temp[k++] = L[i++];
    while (j <= h) 
        temp[k++] = L[j++];
    for (i = l, k = 0; i <= h; i++, k++) 
        L[i] = temp[k];
    delete []temp;
}

void MergeSort(int* L, int len) {
    int size = 1, l, m, h;
    while (size <= len) {
        l = 0;
        while (l + size <= len) {
            m = l + size - 1;
            h = m + size;
            if (h  > len) 
                h = len;
            Merge(L, l, m, h);
            l = h + 1;
        }
        size *= 2;
    }
}

int main(){
    int L[9] = {8, 6, 7, 9, 1, 3, 2, 5, 4};
    int len = sizeof(L) / sizeof(L[0]);
    MergeSort(L, len);
    for (auto L : L) {
        cout << L << endl;
    }
    cin >> len;
    return 0;
}