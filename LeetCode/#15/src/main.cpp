//#15 三数之和
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
// 使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)// 因为递增，后面的都大于零，不可能和为零。
                return ans;
            // 变成滑动窗口问题
            int left = i + 1, right = nums.size()-1;
            while (left < right)
            {
                if (nums[i] + nums[left] > 0 - nums[right])// 这种加减运行考虑溢出
                    right--;
                else if (nums[i] + nums[left] < 0 - nums[right])//
                    left++;
                else
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    // 避免因为相邻数相等造成重复解
                    while (left < right && nums[left] == nums[left+1])
                        left++;
                    while (left < right && nums[right] == nums[right-1])
                        right--;
                    // 必须左右都移动 只移动一个和必不为零
                    left++;
                    right--;
                }
            }          
            // 上面if中先移动左右指针，nums[i]的全部处理完以后，再跳重复的nums[i]
            while (i+1 < nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> v = s.threeSum2(nums);
    for (auto v1 : v)
    {
        for (auto v2 : v1)
        {
            printf("%d ",v2);
        }
        printf("\n");
    }
}