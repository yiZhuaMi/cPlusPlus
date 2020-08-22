// 岛屿系列
// 实现一个函数添加一块陆地，并返回当前的岛屿数量

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printLand(const vector<vector<int>>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            printf("%d",nums[i][j]);
            if (j != nums[i].size() - 1)
                printf(" ");
        }
        printf("\n");
    }
    
}

int island_num = 0;

int addLand(vector<vector<int>>& nums, int i, int j)
{
    if (i < 0 || i >= nums.size() || j < 0 || j >= nums[i].size())
        return island_num;

    if (nums[i][j] == 1)
        return island_num;
    nums[i][j] = 1;

    printLand(nums);

    int around_num = 0;
    if (i - 1 >= 0 && nums[i-1][j] == 1)
        around_num += nums[i-1][j];
    if (i + 1 < nums.size() && nums[i+1][j] == 1)
        around_num += nums[i+1][j];
    if (j - 1 >= 0 && nums[i][j-1] == 1)
        around_num += nums[i][j-1];
    if (j + 1 < nums.size() && nums[i][j+1] == 1)
        around_num += nums[i][j+1];
    
    if (around_num == 0)
        island_num++;
    else
        island_num -= around_num - 1;
    return island_num;
}

int main() 
{
    vector<vector<int>> nums = {{0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0}};
    cout<<addLand(nums,0,4)<<endl;
    cout<<addLand(nums,1,1)<<endl;
    cout<<addLand(nums,1,2)<<endl;
    cout<<addLand(nums,1,3)<<endl;
    cout<<addLand(nums,1,4)<<endl;
}