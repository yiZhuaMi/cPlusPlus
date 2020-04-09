// #面试题42 连续子数组的最大和
// 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
// 要求时间复杂度为O(n)。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;// dp[i] 代表以元素 nums[i] 为结尾的连续子数组最大和
        dp.push_back(nums[0]);
        int max = dp[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (dp[i-1] > 0)
            {
                dp.push_back(nums[i] + dp[i-1]);
            }
            else
            {
                dp.push_back(nums[i]);
            }
            if (dp[i] > max)
                max = dp[i];
        }            
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> list = {-2,1,-3,4,-1,2,1,-5,4};
    printf("[%d]",s.maxSubArray(list));
}