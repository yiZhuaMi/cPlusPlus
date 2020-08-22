// #88. 合并两个有序数组
// 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
// 说明:
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    inline void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // 双指针，从后往前，无需挪动nums1前面的元素
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.empty())
            return;
        if (nums1.empty())
        {
            nums1 = nums2;
            return;
        }
        // 从后往前，先放大的
        // 分别指向两个数组待比较的元素
        int p1 = m - 1, p2 = n - 1;
        // 插入的位置
        int ind = m + n - 1;
        while (ind >= 0)
        {
            if (p1 >= 0 && p2 >= 0)
                nums1[ind--] = nums1[p1] >= nums2[p2] ? nums1[p1--] : nums2[p2--];
            else if (p2 >= 0)
                nums1[ind--] = nums2[p2--];
            // 只剩p1就不用变了
            else
                break;      
        }
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0)
            nums1 = nums2;

        int ind1 = m - 1, ind2 = n - 1, ind = m + n - 1;
        while (ind1 >= 0 && ind2 >= 0)
            nums1[ind--] = nums1[ind1] >= nums2[ind2] ? nums1[ind1--] : nums2[ind2--];

        while (ind2 >= 0)
            nums1[ind--] = nums2[ind2--];
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {4,5,6};
    s.merge(nums1,3,nums2,3);
    // for (size_t j = 0; j < v[i].size(); j++)
    // {
    //     printf("%d ",v[i][j]);
    // }
    // printf("]\n");
}