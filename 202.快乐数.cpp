/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

/*
两个思路:
1.n出现重复值就一定是循环的，
2.可以根据n值的特征，比如出现某个值就一定是循环的。
总之是要确定return false的条件。
所有不快乐数的数位平方和计算，最後都会进入 
4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中。
*/
class Solution {
public:
    vector<int> vec {4, 16, 37, 58, 89, 145, 42, 20};
    vector<int>::iterator pos;
    bool isHappy(int n) {
        pos = find(vec.begin(), vec.end(), n);
        if (pos != vec.end()) return false;
        int next = 0;
        while (n) {
            next += pow(n % 10, 2);
            n /= 10;
        }
        if (next == 1) return true;
        return isHappy(next);
    }
};


// 解法2：
class Solution {
public:
    bool isHappy(int n) {
        string  str;
        int tmp = n;
        for(int i=0;i<6;i++)//快乐就完事了，我也不知道为啥取6
        {
            str = to_string(tmp);
            tmp = 0;
            for(auto c : str)
            {
                tmp += (c-'0') * (c-'0');
            }
            if(tmp == 1)
                return true;
        }
        return false;
    }
};
