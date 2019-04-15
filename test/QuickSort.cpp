#include <iostream>
#define MAXSIZE 10
using namespace std;
struct SqList {
    int r[MAXSIZE + 1];
    int length;
};

void swap (SqList *L, int i, int j) {
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

int Partition(SqList *L, int low, int high) {
    int pivotkey;
    pivotkey = L->r[low];
    while(low < high) {
        while(low < high && L->r[high] >= pivotkey) {
            high--;
        }
        swap(L, low, high);
        while(low < high && L->r[low] <= pivotkey) {
            low++;
        }
        swap(L, low, high);
    }
    return low;
}

void QSort(SqList *L, int low, int high) {
    int pivot;
    if(low < high) {
        pivot = Partition(L, low, high);
        QSort(L, low, pivot - 1);
        QSort(L, pivot + 1, high);
    }
}

void QuickSort (SqList *L) {
    QSort(L, 0, L->length-1);
}

int main() {
    SqList L = {{5, 1, 9, 3, 7, 4, 8, 6, 2}, 9};
    QuickSort(&L);
    for (int i=0; i<L.length; ++i){
        cout << L.r[i] <<endl;
    }
    return 0;
}
