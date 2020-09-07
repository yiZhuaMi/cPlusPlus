// #350. 两个数组的交集 II
// 给定两个数组，编写一个函数来计算它们的交集。
// 示例 1:
// 输入: nums1 = [1,2,2,1], nums2 = [2,2]
// 输出: [2,2]
// 示例 2:
// 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出: [4,9]
// 说明：
// 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
// 我们可以不考虑输出结果的顺序。
// 进阶:
// 如果给定的数组已经排好序呢？你将如何优化你的算法？
// 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
// 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    // 哈希表
    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        vector<int> res;
        for (auto i : nums1)
            m[i]++;
        for (auto j : nums2)
        {
            if (m.find(j) != m.end())
            {
                res.push_back(j);
                if (--m[j] <= 0)
                    m.erase(j);
            }
        }
        return res;
    }

    // 如果给定的数组已经排好序呢？你将如何优化你的算法？
    // 双指针
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while (p1 < nums1.size() && p2 < nums2.size())
        {
            if (nums1[p1] > nums2[p2])
                p2++;
            else if (nums[p1] < nums2[p2])
                p1++;
            else
            {
                res.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {4,9,5};
    vector<int> v2 = {9,4,9,8,4};
    s.intersect(v1,v2);
}