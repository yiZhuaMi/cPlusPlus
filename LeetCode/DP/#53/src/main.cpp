//#53 最大子序和
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 时间复杂度：O(n) 空间复杂度：O(n)
    int maxSubArray2(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.empty() ? 0 : nums[0];
        vector<int> dp(nums.size(),0);// dp[i]:以nums[i]结尾的和最大的连续子序列的和
        dp[0] = nums[0];
        int max = dp[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            // 转换方程 
            dp[i] = dp[i-1] < 0 ? nums[i] : dp[i-1]+nums[i];
            if (dp[i] > max)
                max = dp[i];
        }
        return max;
    }

    // 时间复杂度：O(n) 空间复杂度：O(1)
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.empty() ? 0 : nums[0];
        int sum = 0;
        int max = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (sum > 0)// 和>0 我就参和一下
                sum += nums[i];
            else
                sum = nums[i];// 否则自己另起炉灶

            if (sum > max)
                max = sum;
        }
        return max;
    }
};

int main()
{
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    printf("%d\n",s.maxSubArray(v));
}