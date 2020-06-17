// #面试题53-I 在排序数组中查找数字 I
// 统计一个数字在排序数组中出现的次数。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 用二分法找到目标子串的左边界
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0] == target ? 1 : 0; 
        
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (left + 1 == right && nums[left] != target && nums[right] != target)
                return 0;
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)// 左边界在右半
            {
                if (nums[left+1] == target)
                {
                    left++;
                    break;
                }
                left = mid;
            }
            else if (nums[mid] > target)// 左边界在左半
                right = mid;
            // (nums[mid] == nums[target])
            else if (mid == 0 || nums[mid-1] != target)// 左边界在mid
            {
                left = mid;
                break;
            }
            else// 左边界在mid左边
                right = mid;
        }
        // 左边界left
        int count = 0;
        while (left < nums.size() && nums[left++] == target)
            count++;
        return count;
    }
};

int main()
{
    Solution s;
    // vector<int> v = {5,7,7,8,8,10};
    vector<int> v = {2,2};
    printf("%d",s.search(v,2));
}