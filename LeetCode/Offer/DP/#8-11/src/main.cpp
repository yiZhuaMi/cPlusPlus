// #面试题 08.11. 硬币
// 给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToChange(int n) {
        vector<int>dp(n+1);
        dp[0] = 1;
        int mod = 1000000007;
        int coins[4] = {1,5,10,25};
        // 一次遍历一种硬币
        for (int i = 0; i < 4; i++)
        {
            // 用这个硬币为和为j的结果增添方案
            for (int j = 1; j <= n; j++)
            {
                if (coins[i] <= j)
                {
                    // 当目标为j时，仅用一个coins[i]硬币，只能找目标为j-coins[i]的硬币组合来配对
                    dp[j] = (dp[j] + dp[j - coins[i]]) % mod; 
                }
            }
        }
        return dp[n];
    }
};

int main()
{   
    Solution s;
    printf("%d",s.waysToChange(5));
}