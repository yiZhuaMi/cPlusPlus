// #209 长度最小的子数组
// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度
// 最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
// 示例：
// 输入：s = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 进阶：
// 如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 从左往右 滑动窗口
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int left = 0, right = 0, sum = 0, res = INT32_MAX;
        // right扩张窗口
        while (right < nums.size())
        {
            sum += nums[right];
            // right先扩张到 >=s 就收缩left
            while (sum >= s)// 注意：while!!!!!!!!!!!!
            {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return res == INT32_MAX ? 0 : res;
    }

    int minSubArrayLen2(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int left = 0, right = 0, sum = 0, res = INT32_MAX;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum >= s)
            {
                res = min(res,right-left+1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return res == INT32_MAX ? 0 : res;
    }
};

int main()
{   
    Solution s;
    vector<int> v = {1,2,3,4,5};
    s.minSubArrayLen(11,v);
}