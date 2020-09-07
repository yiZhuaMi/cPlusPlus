//#120 三角形最小路径和
// 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
// 例如，给定三角形：
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 自顶向下
    int minimumTotal2(vector<vector<int>>& triangle) {
        if (triangle.size() < 2)
            return triangle.empty() ? 0 : triangle[0][0];
        
        // dp[i][j]:以triangle[i][j]为结尾的最小路径和
        vector<vector<int>> dp = triangle;
        dp[0][0] = triangle[0][0];
        
        int min_sum = INT32_MAX;
        for (size_t i = 1; i < triangle.size(); i++)// 从第二行开始
        {
            for (size_t j = 0; j < triangle[i].size(); j++)
            {
                // 转换方程
                // dp[i][j] = triangle[i][j] + min(dp[i-1][j-1],dp[i-1][j])
                if (j == 0)
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                else if (j == triangle[i].size()-1)
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                else
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j-1],dp[i-1][j]);
                
                if (i == triangle.size()-1)// 最底层
                    if (dp[i][j] < min_sum)
                        min_sum = dp[i][j];
            }
        }
        return min_sum;
    }

    // 复习
    // 自底向上 无需dp 在triangle上原地修改 输出 [0][0]
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() < 2)
            return triangle.empty() ? 0 : triangle[0][0];
        for (int i = triangle.size()-2; i >= 0; i--)// 从倒数第二行开始
            for (int j = 0; j < triangle[i].size(); j++)
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j],triangle[i+1][j+1]);    
        return triangle[0][0];             
    }
};

int main()
{
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
    // vector<vector<int>> v = {{-10}};
    Solution s;
    printf("%d\n",s.minimumTotal(v));
}