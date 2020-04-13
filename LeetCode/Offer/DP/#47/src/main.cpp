// #面试题47 礼物的最大价值
// 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
// 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
// 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // dp[i] [j] = max(dp[i-1][j]，dp[i][j-1]) + arr[i][j];
    int maxValue(vector<vector<int>>& grid) {

        vector<vector<int>> dp;//dp[i][j]:走到该位置上最大的价值

        for (size_t i = 0; i < grid.size(); i++)
        {
            vector<int> d(grid[0].size(),0);
            dp.push_back(d);
        }
        int max = grid[0][0];
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (i + j == 0)
                {
                    dp[i][j] = grid[0][0];
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                else
                {
                    dp[i][j] = (dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j]) + grid[i][j];
                }
                if (dp[i][j] > max)
                    max = dp[i][j];            
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> list = {{1,3,1},{1,5,1},{4,2,1}};
    printf("%d",s.maxValue(list));
}