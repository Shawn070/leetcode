#include <iostream>
using namespace std;

int main(){
    int n, cnt = 0;
    long maxn = 0;
    cin >> n;
    if (n <= 0) return 0;
    long *num = new long(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    maxn = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] >= maxn) {
            cnt++;
            maxn = num[i];
        }


    }
    cout << cnt + 1 << endl;
    return 0;
}
