// #54. 螺旋矩阵
// 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        // 状态
        const int j_add = 0, i_add = 1, j_dec = 2, i_dec = 3;
        int row = matrix.size(), col = matrix[0].size();
        // 初始状态
        int state = col > 1 ? j_add : i_add;
        // 指针和墙
        int i = 0, j = 0, wall = 0;
        vector<int> res;
        while (res.size() < row * col)
        {
            res.push_back(matrix[i][j]);
            switch (state)
            {
            case j_add:
                j++;
                if (j >= col - 1 - wall)
                    state = i_add;
                break;

            case i_add:
                i++;
                if (i >= row - 1 - wall)
                    state = j_dec;
                break;
            
            case j_dec:
                j--;
                if (j <= 0 + wall)
                    state = i_dec;
                break;

            case i_dec:
                i--;
                if (i <= 1 + wall)// 进入下一圈
                {
                    state = j_add;
                    wall++;
                }
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> v = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    vector<vector<int>> v = {{3},{2}};
    s.spiralOrder(v);
}