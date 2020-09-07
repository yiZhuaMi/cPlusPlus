// #504 七进制数
// 给定一个整数，将其转化为7进制，并以字符串形式输出。
// 示例 1:
// 输入: 100
// 输出: "202"
// 示例 2:
// 输入: -7
// 输出: "-10"
// 注意: 输入范围是 [-1e7, 1e7] 。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        string res;
        while (num != 0)
        {
            if (num > -10 && num < 10)
            {
                int sign = 1;
                if (num < 0)
                {
                    sign = -1;
                    num *= -1;
                }
                    
                res.push_back(num % 7 + '0');
                num /= 7;
                if (num != 0)
                    res.push_back('1');
                if (sign == -1)
                    res.push_back('-');
            }
            else
            {
                // int n = abs(num) % 7;
                res.push_back(abs(num) % 7 + '0');
            }
            num /= 7;
        }
        return string(res.rbegin(),res.rend());
    }

    // 题目有范围限制，可以不考虑取绝对值后溢出
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        int sign = num > 0 ? 1 : -1;
        num = abs(num);
        string res;
        while (num)
        {
            res.push_back(num % 7 + '0');
            num /= 7;
        }
        if (sign < 0)
            res.push_back('-');
        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
    Solution s;
    printf("%s\n",s.convertToBase7(-10).c_str());
}