/*
����������ת��������
*/

#include <string>
#include <iostream>
using namespace std;


const string num0[10] = { "��", "һ", "��", "��", "��", "��", "��", "��", "��", "��" };
const string num1[] = { "", "ʮ", "��", "ǧ" };
const string num2[] = { "", "��", "��", "����" };
const string nagtive = "��";
bool flag0;

string addToNum(string sub) {
    string res;
    int pos = 0;
    for (int i = 0; i <= 3; i++) {
        if (sub.length() == 4 - i && sub[pos] != '0') {
            if (flag0) {
                res += num0[0];
            }
            res += num0[sub[pos] - '0'];
            res += num1[3 - i];
            sub.erase(0, 1);
            flag0 = 0;
        }
        else if (sub.length() == 4 - i && sub[pos] == '0') {
            flag0 = 1;
            //res += num0[0];
            sub.erase(0, 1);
        }
    }
    return res;
}

void main() {
    string num;
    cerr << "����һ��������";
    while (cin >> num) {
        label:for (int i = 0; i < num.length(); i++) {
            if ((num[0] == '+' || num[0] == '-') && i == 0)
                continue;
            if (num[i] < '0' || num[i] > '9') {
                cerr << "����������һ����ȷ�İ��������֣�";
                cin >> num;
                goto label;
            }
        }
        string res, n, numsub;
        int len = num.length();
        bool isNegative = 0;
        flag0 = 0;
        if (num[0] == '+')
            num.erase(0, 1);
        else if (num[0] == '-')
        {
            isNegative = 1;
            num.erase(0, 1);
        }
        if (!num.empty()) {
            //�����λ0
            while (num[0] == '0')
                num.erase(0, 1);
            for (int i = 3; i >= 0; i--) {  //����ȡ��1~4λ��
                if (num.length() > i * 4) {
                    if (i != 0) {
                        numsub = num.substr(0, num.length() - (i * 4));
                        num.erase(0, num.length() - (i * 4));
                    }
                    else {  //���1~4λ��
                        numsub = num;
                        num.clear();
                    }
                    res += addToNum(numsub);
                    res += num2[i];
                }
            }
        }
        if (isNegative)     //����
            res = nagtive + res;
        if (res.empty())    //��
            res = "��";
        cout << res << endl;
        cerr << "����һ��������";
    }
    return ;
}