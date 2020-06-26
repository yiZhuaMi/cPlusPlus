// #70. 爬楼梯
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
// 注意：给定 n 是一个正整数。

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        vector<int> dp(n+1);//dp[i]:爬上第i阶有dp[i]中方法
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.climbStairs(3));
}