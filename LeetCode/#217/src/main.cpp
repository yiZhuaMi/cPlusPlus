// #217. 存在重复元素
// 给定一个整数数组，判断是否存在重复元素。
// 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate2(vector<int> &nums)
    {
        if (nums.empty())
            return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i+1])
                return true;
        }
        return false;
    }

    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() == nums.size() ? false : true;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 3};
    printf("%d\n", s.containsDuplicate(v));
}