// #221 最大正方形
// 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

// 示例:

// 输入: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// 输出: 4

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));// dp[i][j]:以matrix[i][j]为右下角的最大正方形边长
        int max_len = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // 第一行／第一列都等于自己
                if (i * j == 0)
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if (matrix[i][j] == '1')
                {
                    // 复习：必须取min，左上、左、上中有一个为0就不能参与正方形
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
                max_len = max(max_len,dp[i][j]);
            }   
        }
        return max_len * max_len;
    }
};

int main()
{
    vector<vector<char>> v = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution s;
    printf("%d\n",s.maximalSquare(v));
}