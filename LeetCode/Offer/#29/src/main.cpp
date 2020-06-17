// #面试题29 顺时针打印矩阵
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = 0, wall = 0;// 走完一层，多一层不可走的墙
        bool i_add, i_dec, j_add, j_dec;        
        if (col > 1)// 第一步向右
        {
            i_add = false; i_dec = false; j_add = true; j_dec = false;        
        }
        else// 第一步向下
        {
            i_add = true; i_dec = false; j_add = false; j_dec = false;        
        }
        
        vector<int> res;
        while (res.size() < row * col)
        {
            res.push_back(matrix[i][j]);
            int szie = res.size();
            if (i == j + 1 && j_add == true)
            {
                wall++;
            }
            if (j_add)
            {   
                j++;
                if (j == col - 1 - wall)// 右边
                {
                    i_add = true; i_dec = false; j_add = false; j_dec = false;
                }
            }
            else if (i_add)
            {
                i++;
                if (i == row - 1 - wall)// 下边
                {
                    i_add = false; i_dec = false; j_add = false; j_dec = true;
                }
            }
            else if (j_dec)
            {
                j--;
                if (j == 0 + wall)// 左边
                {
                    i_add = false; i_dec = true; j_add = false; j_dec = false;
                }
            }
            else if (i_dec)
            {
                i--;
                if (i == 0 + wall + 1)
                {
                    i_add = false; i_dec = false; j_add = true; j_dec = false;                
                }
            }
        }
        return res;
    }
};

int main()
{   
    Solution s;
    // vector<vector<int>> in = {{2,3,4},{5,6,7},{8,9,10},{11,12,13}};
    vector<vector<int>> in = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> in = {{3},{2}};
    s.spiralOrder(in);
}