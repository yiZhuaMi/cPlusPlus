// 152 乘积最大子数组
// 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct2(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.empty() ? 0 : nums[0];
        int res = nums[0];
        int imax = 1, imin = 1;// 复习：以当前值结尾的连续子数组的乘积的最值
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)// 此时乘以imax会变最小，乘以imin会变大，所以交换
            {
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(imax*nums[i],nums[i]);
            imin = min(imin*nums[i],nums[i]);            
            if (imax > res)
                res = imax;            
        }
        return res;
    }

    int maxProduct(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.empty() ? 0 : nums[0];
        vector<int> dp_max(nums.size(),0);
        vector<int> dp_min(nums.size(),0);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int res = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                dp_max[i] = max(nums[i],nums[i]*dp_max[i-1]);
                dp_min[i] = min(nums[i],nums[i]*dp_min[i-1]);
            }
            else
            {
                dp_max[i] = max(nums[i],nums[i]*dp_min[i-1]);
                dp_min[i] = min(nums[i],nums[i]*dp_max[i-1]);
            }
            res = max(res,dp_max[i]);
        }
        return res;        
    }
};

int main()
{
    vector<int> v = {-4,-3,-2};
    Solution s;
    printf("%d\n",s.maxProduct(v));
}