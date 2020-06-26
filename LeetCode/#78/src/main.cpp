// #78. 子集
// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
// 说明：解集不能包含重复的子集。
// 示例:
// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<vector<int>> res;
        vector<int> ans;
        dfs(nums,res,ans,0);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& ans, int start)
    {
        res.push_back(ans);
        for (int i = start; i < nums.size(); i++)
        {
            ans.push_back(nums[i]);
            dfs(nums,res,ans,i+1);// i+1 !!!!!!!!!!! 从左往右组合，不回头，就不会重复，本身也没有重复的数
            ans.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> v = s.subsets(nums);
    for (size_t i = 0; i < v.size(); i++)
    {
        printf("[");
        for (size_t j = 0; j < v[i].size(); j++)
        {
            printf("%d ",v[i][j]);
        }
        printf("]\n");
    }
    printf("]");
}