// #198 打家劫舍
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯
// 一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小
// 偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够
// 偷窃到的最高金额。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;
        if (grid[i][j] == '0')
            return 0;
        // 原地标记访问过的
        grid[i][j] = '0';
        
        // 相通的全部置0
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int max_num = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                max_num += dfs(grid,i,j);
            }
        }
        return max_num;
    }
};

int main()
{
    vector<vector<char>> v = {{'1','1','0','0','0'},
                             {'1','1','0','0','0'},
                             {'0','0','0','1','1'},
                             {'0','0','0','1','1'}};
    Solution s;
    s.numIslands(v);
}