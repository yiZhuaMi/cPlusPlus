// #面试题59 - I. 滑动窗口的最大值
// 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出: [3,3,5,5,6,7]
// 解释:
//   滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty())
            return {};
        if (nums.size() == 1)
            return {nums[0]};
        deque<int> q; // 双端队列
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            // 复习：q中维护从尾到头的递增序列
            while (!q.empty() && nums[i] > q.back()) // 比nums[i]小的全部弹出 再加入nums[i]
                q.pop_back();
            // nums[i]进入窗口时，队列中至少会有一个就是自己
            q.push_back(nums[i]); // 这样使得队列从尾到头递增

            if (i >= k && nums[i-k] == q.front()) // 需要右移窗口了 && 移出窗口的是窗口中的最大值，也就是队头
                q.pop_front();

            if (i >= k - 1)// 窗口完整了，可以开始记录最大值
                res.push_back(q.front());
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    v = s.maxSlidingWindow(v, 3);
    for (auto c : v)
        printf("%d ", c);
}