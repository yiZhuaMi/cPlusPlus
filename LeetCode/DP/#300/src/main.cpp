//#300 最长上升子序列

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 求最长子序列 不需要连续！！！(子串才是连续的)
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        // 状态定义
        // dp[i] 表示以 nums[i] 结尾的「最长上升子序列」的长度(不一定是最大的)。
        // 注意：这个定义中 nums[i] 必须被选取，且必须是这个子序列的最后一个元素。
        // 转移方程
        // dp[i+1] = nums[i+1]之前所有(比其小的num对应的dp)中最大的dp+1
        vector<int> dp;
        dp.push_back(1);// dp[0]=1
        int max = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            int max_dp = 0;
            for (size_t j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[j] > max_dp)
                {
                    max_dp = dp[j];
                }
            }
            dp.push_back(max_dp+1);
            if (dp[i] > max)
                max = dp[i];
        }
        // 这里要注意，不能返回最后一个状态值dp[dp.size()-1]；
        // 还是根据定义，最后一个状态值只是以 nums[len - 1] 结尾的「上升子序列」的长度；
        // 状态数组 dp 的最大值才是最后要输出的值。
        return max;
    }
};

int main()
{
    vector<int> v = {1,3,6,7,9,4,10,5,6};
    Solution s;
    printf("%d\n",s.lengthOfLIS(v));
}