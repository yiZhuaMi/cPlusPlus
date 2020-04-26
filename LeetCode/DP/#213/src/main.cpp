//#213 打家劫舍 II
// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋
// 都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通
// 的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够
// 偷窃到的最高金额。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 最后一家不偷 正偷一遍 反偷一遍
    int rob(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.empty() ? 0 : nums[0];
        int len = nums.size();
        vector<int> dp(len,0);// dp[i]:在此位置上能偷到的最大金额
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        int res1 = max(dp[0],dp[1]);
        for (size_t i = 2; i < len; i++)// 从第三家开始
        {
            if (i != len-1)
                dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
            res1 = max(res1,dp[i]);
        }
        dp[len-1] = nums[len-1];
        dp[len-2] = max(nums[len-1],nums[len-2]);
        int res2 = max(dp[0],dp[1]);
        for (int i = len-3; i >=0; i--)// 从倒数第三家开始
        {
            if (i != 0)
                dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
            res2 = max(res2,dp[i]);
        }
        return max(res1,res2);
    }
};

int main()
{
    vector<int> v = {1,2,1,1};
    Solution s;
    printf("%d\n",s.rob(v));
}