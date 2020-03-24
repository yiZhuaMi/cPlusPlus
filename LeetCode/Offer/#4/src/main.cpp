//#面试题4 二维数组中的查找

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(int target, vector<vector<int> > matrix) {
        
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        for (size_t i = 0; i < row; i++)// 行
        {
            if (matrix[i][0] > target || matrix[i][col-1] < target)
                continue;
        
            for (size_t j = 0; j < col; j++)// 列
                if (matrix[i][j] == target)
                    return true;
        }
        return false;
    }
};

int main()
{   
    // vector<vector<int> > v = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int> > v = {{}};
    Solution s;
    printf("%d\n",s.findNumberIn2DArray(1,v));
}