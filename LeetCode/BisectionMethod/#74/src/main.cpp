// #74 搜索二维矩阵
// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

// 每行中的整数从左到右按升序排列。
// 每行的第一个整数大于前一行的最后一个整数。
// 示例 1:

// 输入:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// 输出: true

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 双指针
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int row = 0, col = matrix[0].size() - 1;
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

    // 二分 待解决
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    }
};

int main()
{   
    Solution s;
    s.mySqrt(4);
}