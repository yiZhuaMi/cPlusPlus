//#面试题17.16 按摩师
// 一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
// 在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约
// 请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.empty() ? 0 : nums[0];
        if (nums.size() == 2)
            return max(nums[0],nums[1]);
        
        vector<int> dp(nums.size(),0);// dp[i]:第i个位置(选择i+1号预约)最大总时长
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);// 这里也可以选择dp[i-1]放弃nums[1]!!!!!!!!!!!!
        
        int total_max = 0;
        for (size_t i = 2; i < nums.size(); i++)
        {
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);// dp[i-1]:不选择nums[i],保留之前更大的
            total_max = max(total_max,dp[i]);
        }
        return total_max;
    }
};

int main()
{   
    vector<int> v = {1,2,3,10};
    Solution s;
    printf("%d",s.massage(v));
}