/*
求最长公共子串
*/

#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    string str1, str2;
    int cnt = 0;
    str1 = "asd12345qwer";
    str2 = "asdd1234_5qwerfff";
    //cin >> str1;
    //cin >> str2;
    
    if (str1.length() < str2.length()) 
    {
        string temp = str1;
        str1 = str2;
        str2 = temp;
    }
    if (str1.empty() || str2.empty()) 
        cout << "";
    string res, temp;
    int i = 0, j = 0;

    while(i < str1.length())
    {
        int oldi = i;
        for (j = 0;j < str2.length(); j++)
        {
            if (str1[i] == str2[j] && i < str1.length()) 
            {
                temp.push_back(str1[i]);
                i++;
                if (temp.length() > cnt)
                {
                    cnt = temp.length();
                    res = temp;
                }
            }
            else
            {
                if (temp.length() == cnt)
                    i = oldi;
                temp = "";
                
            }
        }
        i = oldi;
        temp = "";
        i++;
    }
    cout << res << endl;
    system("pause");
    return 0;
}