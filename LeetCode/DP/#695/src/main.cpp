// #695 岛屿的最大面积
// 给定一个包含了一些 0 和 1 的非空二维数组 grid 。

// 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

// 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

 

// 示例 1:

// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

// 示例 2:

// [[0,0,0,0,0,0,0,0]]
// 对于上面这个给定的矩阵, 返回 0。

 

// 注意: 给定的矩阵grid 的长度和宽度都不超过 50。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void print_island(const vector<vector<int>>& grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                printf("%d ",grid[i][j]);
            }
            printf("\n");
        }
    }

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;
        if (grid[i][j] == 0)
            return 0;
        // printf("=========\n");
        // print_island(grid);
        // printf("dfs %d %d\n",i,j);
        // 原地记录已经访问的点
        grid[i][j] = 0;
        // dfs遍历该点的上下左右四个方向
        return 1 + dfs(grid,i-1,j) + dfs(grid,i+1,j) + dfs(grid,i,j-1) + dfs(grid,i,j+1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    res = max(res,dfs(grid,i,j));
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> v = {{1,1,0,0,0},
                             {1,1,0,0,0},
                             {0,0,0,1,1},
                             {0,0,0,1,1}};
    Solution s;
    s.maxAreaOfIsland(v);
}