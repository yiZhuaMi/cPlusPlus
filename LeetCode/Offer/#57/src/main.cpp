// #面试题57. 和为s的两个数字
// 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 二分
    vector<int> twoSum2(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= target || target - nums[i] <= nums[i])
                continue;
            int secondOne = target - nums[i];// 二分查找的目标
            int left = 0, right = nums.size() - 1;
            
            while (left <= right)// 左右重合则secondOne只有一个可选
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] < secondOne)
                {
                    left = mid + 1;
                }
                else if (nums[mid] > secondOne)
                {
                    right = mid - 1;
                }
                else
                {
                    return {nums[i],nums[mid]};
                }                
            }            
        }
        return {};
    }    

    // 滑动窗口
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right)
            if (nums[left] + nums[right] < target)
                left++;
            else if (nums[left] + nums[right] > target)
                right--;
            else
                return {nums[left],nums[right]};            
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> v = {10,26,30,31,47,60};
    v = s.twoSum(v,40);
    printf("%d %d",v[0],v[1]);
}