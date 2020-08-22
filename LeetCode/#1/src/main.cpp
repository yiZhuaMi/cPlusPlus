//#1.两数之和
//用break会终止内层循环

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum2(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)//直接i+1
            {
                if(nums.at(i) + nums.at(j) == target)
                {
                    return {i,j};//无需新声明vector
                }
            }    
        }
        return {0};
    }

    // 先排序 再二分 可以找值 下标不太方便
    vector<int> twoSum3(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size() && nums[i] < target; i++)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                int a = nums[mid], b = target - nums[i];
                if (nums[mid] > target - nums[i])
                {
                    right = mid - 1;
                }
                else if (nums[mid] < target - nums[i])
                {
                    left = mid + 1;
                }
                else
                {
                    return {i,mid};
                }
            }
        }
        return {};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // <nums[i],i>
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) != m.end())
                return {i,m[target - nums[i]]};
            m[nums[i]] = i;// 后添加当前数，否则可能1+1=2
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {3,2,4};
    int target = 6;
    Solution s;
    nums = s.twoSum(nums,target);
    printf("[%d, %d]\n",nums[0],nums[1]);
}