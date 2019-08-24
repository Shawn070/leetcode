#include <iostream>
using namespace std;

int main(){
    int n, cnt=0, cntH=0, cntL=0;
    string str;
    cin >> n;
    cin >> str;
    bool isLarge = 0, is3H = 0;
/*    for (int i=0; i < n; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (cntH > 3)
                cnt += cntH+2;
            else
                cnt += cntH*2;
            cntL++;
            cntH=0;
        }
        else {
            if (cntL > 3)
                cnt += cntL+2;
            else
                cnt += cntL*2;
            cntH++;
            cntL=0;
        }
    }
    cnt += cntH + cntL;*/

    for (int i=0; i < n; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (cntH > 3)
                cnt += cntH+2;
            else
                cnt += cntH*2;
            if (cntL == 0 && str[1+i] >= 'A' && str[1+i] <= 'Z')
                cnt--;
            cntL++;
            cntH=0;
        }
        else {
            if (cntL > 3)
                cnt += cntL+2;
            else
                cnt += cntL*2;
            if (cntH == 0 && str[1+i] >= 'a' && str[1+i] <= 'z')
                cnt--;
            cntH++;
            cntL=0;
        }
    }
    cnt += cntH + cntL;

    cout << cnt << endl;
    return 0;
}
