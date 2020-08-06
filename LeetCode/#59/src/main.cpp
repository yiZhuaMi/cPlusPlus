// #59. 螺旋矩阵 II
// 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
// 示例:
// 输入: 3
// 输出:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0)
            return {};
        // 状态
        const int j_add = 0, i_add = 1, j_dec = 2, i_dec = 3;
        int row = n, col = n;
        // 初始状态
        int state = col > 1 ? j_add : i_add;
        // 指针和墙
        int i = 0, j = 0, wall = 0, val = 0;
        vector<vector<int>> res(n,vector<int>(n,0));
        while (val < row * col)
        {
            res[i][j] = ++val;
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

    vector<vector<int>> generateMatrix2(int n) {
        // 创建二维矩阵
        vector<vector<int>> matrix(n);
        for (int i = 0; i < matrix.size(); i++)
            matrix[i].resize(n);
        // 上下左右
        int u = 0;
        int d = n-1;
        int l = 0;
        int r = n-1;
        int num = 1;

        while(true){
            // 上
            for(int i=l; i <= r; i++) matrix[u][i] = num++;
            if (u++ >= d) break;
            // 右
            for(int i=u; i <= d; i++) matrix[i][r] = num++;
            if (r-- <= l) break;
            // 下
            for(int i=r; i >= l; i--) matrix[d][i] = num++;
            if (d-- <= u) break;
            // 左
            for(int i=d; i >= u; i--) matrix[i][l] = num++;
            if (l++ >= r) break;
        }
        return matrix;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = s.generateMatrix(3);
}