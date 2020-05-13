#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;
    if (row <= 2 || col <= 2)
    {
        cout<<0<<endl;
        return 0;
    }    
    
    vector<vector<int>> v(row,vector<int>(col,0));
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            cin>>v[i][j];
   
    vector<vector<int>> dp(row,vector<int>(col,0));
    // dp[i][j]// 遍历到这个位置为止，出现过的区域数。
    for (size_t i = 1; i < row-1; i++)
    {
        for (size_t j = 1; j < col-1; j++)
        {
            if (i == row-2 && j == col-2)
            {
                if (v[i][j] == 1 && v[i-1][j] != 1 && v[i][j-1] != 1 && v[i+1][j] != 1 && v[i][j+1] != 1)
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
            else if (i == row-2)
            {
                if (v[i][j] == 1 && v[i-1][j] != 1 && v[i][j-1] != 1 && v[i+1][j] != 1)
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
            else if (j == col-2)
            {
                if (v[i][j] == 1 && v[i-1][j] != 1 && v[i][j-1] != 1 && v[i][j+1] != 1)
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
            else
            {
                if (v[i][j] == 1 && v[i-1][j] != 1 && v[i][j-1] != 1)
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
            cout<<"dp "<<dp[i][j]<<endl;
        }
    }
    cout<<dp[row-2][col-2]<<endl;
    return 0;
}