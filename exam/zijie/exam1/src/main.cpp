// 数组有n个元素，范围为[l,r]，对于给定的n、l、r，求元素之和能被3整除的数组个数（对1000000007取模）
// 如输入：2 1 3
// 输出：3（[1，2],[2，1],[3，3]）

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> res;

void dfs(vector<int>& nums, int n, int l, int r)
{
    if (nums.size() >= n + 1)
    {
        if (nums[0] % 3 == 0)
            res.push_back(nums);
        return;
    }

    for (int i = l; i <= r; i++)
    {
        nums[0] += i;
        nums.push_back(i);
        dfs(nums,n,l,r);
        nums.pop_back();
        nums[0] -= i;
    }
}

int main()
{
    int n, l, r;
    cin>>n>>l>>r;
    
    vector<int> nums;
    nums.push_back(0);// 第一个位置记录数字之和
    dfs(nums,n,l,r);
    for (auto n1 : res)
    {
        printf("[");
        for (int i = 1; i < n1.size(); i++)
        {
            printf("%d",n1[i]);
            if (i != n1.size() - 1)
                printf(",");
        }
        printf("]\n");
    }
}