// #162. 寻找峰值
// 峰值元素是指其值大于左右相邻值的元素。
// 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
// 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
// 你可以假设 nums[-1] = nums[n] = -∞。
// 示例 1:
// 输入: nums = [1,2,3,1]
// 输出: 2
// 解释: 3 是峰值元素，你的函数应该返回其索引 2。
// 示例 2:
// 输入: nums = [1,2,1,3,5,6,4]
// 输出: 1 或 5 
// 解释: 你的函数可以返回索引 1，其峰值元素为 2；
//      或者返回索引 5， 其峰值元素为 6。
// 说明:
// 你的解法应该是 O(logN) 时间复杂度的。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 你可以假设 nums[-1] = nums[n] = -∞。
    int findPeakElement(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1;
        // 复习：这里不能相等
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // 不用考虑边界，相邻元素不相等，所以只有两种情况
            if (nums[mid] > nums[mid+1])// 复习：注意这里是mid和mid+1比较
            {
                right = mid;
            }
            // nums[mid] < nums[mid+1]
            else
            {
                left = mid + 1;
            }
        }
        // 最后左右重叠就是目标索引
        return left;        
    }
};

int main()
{   
    Solution s;
    vector<int> v = {1,2,1,3,5,6,4};
    s.findPeakElement(v);
}