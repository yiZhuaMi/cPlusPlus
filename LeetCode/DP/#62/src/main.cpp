// #62 不同路径
// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 问总共有多少条不同的路径？

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 一次性双百！！！
    int uniquePaths(int m, int n) {
        // 所有格子都先被初始化为1
        vector<vector<int>> dp(m,vector<int>(n,1));//dp[i][j]:到ij有多少种路径
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.uniquePaths(3,2));
}