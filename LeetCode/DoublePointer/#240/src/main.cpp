// #240 搜索二维矩阵 II
// 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

// 每行的元素从左到右升序排列。
// 每列的元素从上到下升序排列。
// 示例:

// 现有矩阵 matrix 如下：

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 二维 双指针
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        // 从矩阵的右上角开始
        int row = 0, col = matrix[0].size()-1;
        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] > target)
            {
                col--;
            }
            else if (matrix[row][col] < target)
            {
                row++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{   
    Solution s;
}