// #215 数组中的第K个最大元素
// 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 大根堆
    int findKthLargest2(vector<int>& nums, int k) {
        // less代表 < ,大的优先，先出队，队头／堆顶是大的，所以是大根堆
        priority_queue<int,vector<int>,less<int>> q;
        for (int i = 0; i < nums.size(); i++)
            q.push(nums[i]);
        int res = -1;
        while (k-- > 0)
        {
            res = q.top();
            q.pop();
        }
        return res;
    }

    int findKthLargest2(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};

}