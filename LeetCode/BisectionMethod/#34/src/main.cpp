// #34. 在排序数组中查找元素的第一个和最后一个位置
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
// 你的算法时间复杂度必须是 O(log n) 级别。
// 如果数组中不存在目标值，返回 [-1, -1]。
// 示例 1:
// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]  
// 示例 2:
// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 二分法 寻找左侧边界
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int start = -1, end = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 复习：找左右边界时，不等号中的是一样的！！！！！！
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            // 找到以后不立即返回 而是收缩右边界
            else
                right = mid - 1;// 复习：一定要-1+1，否则超时!!!!!!!!!!!!!!!!!!!!!
        }
        // 由于 while 的退出条件是 left == right + 1，所以当 target 比 nums 中所有元素都大时，最后left==len使得索引越界：
        
        // 复习
        // 退出条件是 left == right + 1
        // 但有两种失败情况：
        // 1.left没有越界，但是nums[left] != target
        // 2.left越界(范围只会缩小，所以left只会变大)
        if (left >= nums.size() || nums[left] != target)
            return {-1,-1};
        // 否则此时left就是左边界
        start = left;

        // 寻找右边界
        right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            // 找到target不直接返回 而是收缩左边界
            else
                left = mid + 1;// !!!!!!!!!!!!!!!!!
        }
        // (范围只会缩小，所以right只会变小)
        if (right < 0 || nums[right] != target)
            return {-1,-1};
        end = right;

        return {start,end};    
    }
};

int main()
{   
    Solution s;
    vector<int> v = {5,7,7,8,8,10};
    s.searchRange(v,3);
}