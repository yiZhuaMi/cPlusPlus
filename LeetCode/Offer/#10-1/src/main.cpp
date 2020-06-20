// #10- I. 斐波那契数列
// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
// 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 取余 (x+y)%p=(x%p+y%p)%p
    int fib(int n) {
        if (n < 2)
            return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i-1] % 1000000007 + dp[i-2] % 1000000007) % 1000000007;
        return dp[n];
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.fib(2));
}