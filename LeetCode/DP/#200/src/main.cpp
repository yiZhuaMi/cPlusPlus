// #200 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
// 示例 1:

// 输入:
// [
// ['1','1','1','1','0'],
// ['1','1','0','1','0'],
// ['1','1','0','0','0'],
// ['0','0','0','0','0']
// ]
// 输出: 1
// 示例 2:

// 输入:
// [
// ['1','1','0','0','0'],
// ['1','1','0','0','0'],
// ['0','0','1','0','0'],
// ['0','0','0','1','1']
// ]
// 输出: 3
// 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

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