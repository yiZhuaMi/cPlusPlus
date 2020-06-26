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
    // 双指针，从后往前，无需挪动nums1前面的元素
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 分别指向两个数组待插入的元素
        int p1 = m - 1;
        int p2 = n - 1;
        // 指向nums1中待插入的位置
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3};

    // for (size_t j = 0; j < v[i].size(); j++)
    // {
    //     printf("%d ",v[i][j]);
    // }
    // printf("]\n");

}