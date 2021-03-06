// 33 搜索旋转排序数组
// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
// 你可以假设数组中不存在重复的元素。
// 你的算法时间复杂度必须是 O(log n) 级别。
// 示例 1:
// 输入: nums = [4,5,6,7,0,1,2], target = 0
// 输出: 4
// 示例 2:
// 输入: nums = [4,5,6,7,0,1,2], target = 3
// 输出: -1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            // mid左边有序
            if (nums[mid] >= nums[left])// 先要确定哪边有序
            {
                // 用mid／left来判断taget在mid左边
                if (target < nums[mid] && target >= nums[left])// 才能通过有序的这一边用比较运算符判断target是否在这一边
                    right = mid - 1;
                // taget在mid右边
                else
                    left = mid + 1;
            }
            // mid右边有序
            else// nums[mid] < nums[left]
            {
                // 用mid／right来判断taget在mid右边
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                // taget在mid左边
                else
                    right = mid - 1;
            }   
        }
        return -1;
    }

    int search2(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            // 左边有序
            if (nums[mid] >= nums[right])// 是否取等号都可以
            {
                // 确定一边有序以后，一定要用mid和right／left来确定
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // 右边有序
            else// if (nums[mid] < nums[right])
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }   
        return -1;  
    }
};

int main()
{   
    Solution s;
    vector<int> v = {2,2,2,3,1};
}