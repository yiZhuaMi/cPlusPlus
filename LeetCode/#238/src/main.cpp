// 238. 除自身以外数组的乘积
// 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，
// 其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
// 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
// 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
// 进阶：
// 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            int ans = 1;
            auto ite = m.find(nums[i]);
            if (ite != m.end())
            {
                res.push_back(ite->second);
            }
            else
            {
                for (int j = 0; j < nums.size(); j++)
                {
                    if (j != i)
                    {
                        ans *= nums[j];                    
                    }
                }
                m[nums[i]] = ans;
                res.push_back(ans);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}