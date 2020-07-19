// #46 全排列
// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 回溯
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res = {};
        vector<int> one_ans;
        vector<bool> used(nums.size(),false);// 用来标记这个数是否已排列过
        dfs(nums,one_ans,used,res);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& one_ans, vector<bool>& used, vector<vector<int>>& res)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (one_ans.size() == nums.size())
            {
                res.push_back(one_ans);
                return;    
            }
            if (used[i] == false)
            {
                one_ans.push_back(nums[i]);
                used[i] = true;
                dfs(nums,one_ans,used,res);
                // 回溯
                used[i] = false;
                one_ans.pop_back();
            }
        }
    }

    vector<vector<int>> res;
    vector<int> one_ans;

    vector<vector<int>> permute2(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        dfs(nums,used);
        return res;
    }

    void dfs(vector<int>& nums, vector<bool>& used)
    {
        if (one_ans.size() == nums.size())
        {
            res.push_back(one_ans);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == false)
            {
                one_ans.push_back(nums[i]);
                used[i] = true;
                dfs(nums,used);
                used[i] = false;
                one_ans.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3};
}