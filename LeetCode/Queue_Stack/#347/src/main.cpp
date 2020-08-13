// #347 前 K 个高频元素
// 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
// 示例 1:
// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
// 示例 2:
// 输入: nums = [1], k = 1
// 输出: [1]
// 提示：
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
// 你可以按任意顺序返回答案。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> m;// <值，频数>
        // 小顶堆 维护频数最高的k个
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;// <频数，值>
        for (auto n : nums)
            m[n]++;
        for (auto ite : m)
        {
            q.push(pair<int,int>(ite.second,ite.first));
            if (q.size() > k)
            {
                q.pop();
            }
        }
        while (q.size() > 0)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return vector<int>(res.rbegin(),res.rend());
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,1,1,2,2,3};
    s.topKFrequent(v,2);
}