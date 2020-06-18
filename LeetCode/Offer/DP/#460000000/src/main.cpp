// #面试题46 把数字翻译成字符串
// 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译
// 成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻
// 译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int translateNum(int num)
    {
        string str = to_string(num);
        int n = str.size();
        vector<int> dp(1 + n);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2, j = num; i <= n; i++)
        {
            if (10 <= j % 100 && j % 100 <= 25)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
            j /= 10;
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    printf("%d", s.translateNum(625));
}