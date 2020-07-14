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
    // 大根堆 全部放入 出队k次
    int findKthLargest1(vector<int>& nums, int k) {
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

    // 小根堆 维护k个 多了就弹出堆顶（最小的） 最后返回堆顶
    int findKthLargest2(vector<int>& nums, int k) {
        // 小根堆
        priority_queue<int,vector<int>,greater<int>> q;
        for (auto n : nums)
        {
            q.push(n);
            if (q.size() > k)
                q.pop();// 弹出最小的
        }
        return q.top();
    }
    
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // 从大到小 快排
    int partition(vector<int>& nums, int k, int left, int right)
    {
        int key = left, r = right;
        while (left < right)
        {
            while (left < right && nums[right] <= nums[key])
                right--;
            while (left < right && nums[left] >= nums[key])
                left++;
            swap(nums[left],nums[right]);
        }
        // 交换key left以及所对应值
        swap(nums[key],nums[left]);
        swap(key,left);
        // 此时key左边都大于key，右边都小于key
        // 此时nums[key]是第key【大】的
        if (key == k)
            return nums[key];
        else if (key < k)
            return partition(nums,k,key + 1,r);// 原来的右边界r
        else
            return partition(nums,k,left,key - 1);// 原来的左边界left
    }

    // 快排思想
    int findKthLargest3(vector<int>& nums, int k) {
        // 第k大 k>=1 
        return partition(nums,k-1,0,nums.size()-1);
    }

    int findKthLargest4(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5,2,4,1,3,6,0};
    s.findKthLargest3(nums,4);
}