// #面试题53-II 0～n-1中缺失的数字
// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
// 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 二分
    int missingNumber2(vector<int>& nums) {
        if (nums.size() == 1)
            return !nums[0];
        int left = 0, right = nums.size() - 1;// 传入的nums大小比实际大小少1
        int res = -1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // 先检查是否找到
            if (mid > 0 && nums[mid] - nums[mid-1] > 1)
            {
                res = nums[mid] - 1;
                break;
            }
            if (mid < nums.size()-1 && nums[mid+1] - nums[mid] > 1)
            {
                res = nums[mid] + 1;
                break;
            }        
            if (nums[mid] == mid)// 下标对应 缺失的在右边
            {
                left = mid + 1;
            }
            else if (nums[mid] > mid)// 缺失在左边
            {
                if (mid - 1 > left)
                    right = mid - 1;
                else
                    return nums[left] - 1;// right移动到left，说明缺失的是nums[left] - 1
            }
            // nums[mid] < mid -> 左边增加了 不可能出现
        }
        return res == -1 ? nums[nums.size()-1] + 1: res;// left移动到right，说明缺失的是nums[len-1] + 1
    }
    // 求和
    int missingNumber3(vector<int>& nums) {
        int sum = (0 + nums.size()) * (nums.size() + 1) / 2;
        int fact = 0;
        for (auto c : nums)
            fact += c;
        return sum - fact;
    }

    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] != mid)// 说明左边有缺失(nums[mid] < mid不可能)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};  

int main()
{
    Solution s;
    vector<int> v = {0,2,3};
    printf("%d",s.missingNumber(v));
}