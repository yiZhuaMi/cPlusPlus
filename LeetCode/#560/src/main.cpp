// #560 和为K的子数组
// 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

// 示例 1 :

// 输入:nums = [1,1,1], k = 2
// 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
// 说明 :

// 数组的长度为 [1, 20,000]。
// 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 前缀和（两项相减得中间项之和）+ 哈希表（无需遍历相减，直接找）
    // 根据当前前缀和，在 map 中寻找「与之相减 == k」的「目标前缀和」。目标前缀和这个数值可能不止出现 1 次，
    // 假设为 n 次，就等价于，能找到 n 个子数组的求和等于 k，遍历 nums 数组每一项，n 不断累加给 count，最后返回 count
    int subarraySum(vector<int>& nums, int k) {
        // <前缀和,出现次数>
        unordered_map<int,int> m;
        m[0] = 1;
        // 总的前缀和
        int presfix_sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 先加上当前数
            presfix_sum += nums[i];
            // 看一下加上了nums[i]的前缀和presfix_sum，有咩有谁能+k=presfix_sum
            if (m.find(presfix_sum - k) != m.end())
            {
                res += m[presfix_sum - k];
            }
            m[presfix_sum]++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3};
    s.subarraySum(v,3);
}