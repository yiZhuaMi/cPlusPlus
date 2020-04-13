//#面试题14-1 剪绳子

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1,0);// dp[i]:长度为i的绳子可得到的最大乘积
        dp[2] = 1;// n=2时 dp[0]=1; 
        // 动态方程:dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]))        (0<j<i)
        // dp[i]:维持原状态不剪
        // j * (i - j):在j处剪断，i~j不再剪，两段长度相乘
        // j * dp[i - j]:在j处剪断，i~j继续剪(取i - j长度的最大乘积)
        for (int i = 3; i <= n; i++)
        {
            for (int j = 2; j < i; j++)
            {
                dp[i] = max(dp[i],max(j * (i - j),j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

int main()
{   
    Solution s;
    printf("%d",s.cuttingRope(10));
}