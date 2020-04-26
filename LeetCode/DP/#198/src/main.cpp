//#198 打家劫舍
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯
// 一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小
// 偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够
// 偷窃到的最高金额。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 双百～
    // 更好的转换方程:dp[i] = max(dp[i-2]+nums[i], dp[i-1])
    // 可以选择不偷！直接选择i-1的总金额
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size(),0);// dp[i]:在i处能偷到的最大金额
        dp[0] = nums[0];
        int total_max = nums[0];
        for (size_t i = 1; i < nums.size(); i++)// 从第二个开始计算
        {
            if (i == 1)
                dp[i] = nums[i];
            else if (i == 2)
                dp[i] = nums[i] + dp[i-2];
            else
                dp[i] = nums[i] + max(dp[i-2],dp[i-3]);// 往前数2个或者3个的最大值(可以覆盖所有位置)
            total_max = max(total_max,dp[i]);
        }
        return total_max;// 不能直接返回最后一个(不一定是最大的)
    }
};

int main()
{
    // vector<int> v = {2,1,1,2};
    vector<int> v = {8,3,5,4,9,22,13};
    Solution s;
    printf("%d\n",s.rob(v));
}