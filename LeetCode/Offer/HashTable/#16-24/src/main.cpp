// #面试题 16.24. 数对和
// 设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。
// 示例 1:
// 输入: nums = [5,6,5], target = 11
// 输出: [[5,6]]
// 示例 2:
// 输入: nums = [5,6,5,6], target = 11
// 输出: [[5,6],[5,6]]
// 提示：
// nums.length <= 100000

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    // 哈希表
    vector<vector<int>> pairSums2(vector<int>& nums, int target) {
        map<int,int> m;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        for (auto ite = m.begin(); ite != m.end(); ite++)
        {
            if (ite->first * 2 > target)
                continue;
            auto another = m.find(target - ite->first);
            if (another != m.end())
                if (another != ite)
                    res.insert(res.end(),min(ite->second,another->second),{ite->first,another->first});
                else if (another == ite && ite->second > 1)
                    res.insert(res.end(),ite->second / 2,{ite->first,another->first});
        }
        return res;
    }

    // 双指针
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        while (left < right)
        {
            if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else if (nums[left] + nums[right] < target)
            {
                left++;
            }
            else
            {
                res.push_back({nums[left++],nums[right--]});
            }            
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-2,-1,0,3,5,6,7,9,13,14};
    s.pairSums(v,12);
}