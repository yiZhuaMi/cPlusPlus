//#4 寻找两个正序数组的中位数
// 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
// 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
// 你可以假设 nums1 和 nums2 不会同时为空。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty())
            return -1;
        int total_len = nums1.size() + nums2.size();
        int mid_ind = total_len % 2 != 0 ? total_len / 2 : total_len / 2 - 1;// 中位数的序号
        int ind1 = 0, ind2 = 0, vir_ind = 0;
        double res = -1;
        
        while (ind1 < (int)nums1.size() && ind2 < (int)nums2.size())
        {
            vir_ind++;// 用于匹配mid_ind
            if (nums1[ind1] <= nums2[ind2])// 从小到大
                ind1++;
            else
                ind2++;
            if (vir_ind == mid_ind)// 找到中位数
            {
                if (total_len % 2 != 0)
                    res = max(nums1[ind1],nums2[ind2]);// 不知掉是谁达到了中位数，但肯定是更大的这个
                else
                    res = (max(nums1[ind1],nums2[ind2]) + min(nums1[ind1+1],nums2[ind2+1])) / 2.0; 
                // break
                ind1 = nums1.size();
                ind2 = nums2.size();
            }
                           
        }
        while (ind1 < nums1.size())
        {
            vir_ind++;
            ind1++;
            if (vir_ind == mid_ind)// 找到中位数
            {
                if (total_len % 2 != 0)
                    res = nums1[ind1];
                else
                    res = (nums1[ind1] + nums1[ind1+1]) / 2.0; 
                break;
            }
        }
        while (ind2 < nums2.size())
        {
            vir_ind++;
            ind2++;
            if (vir_ind == mid_ind)// 找到中位数
            {
                if (total_len % 2 != 0)
                    res = nums2[ind2];
                else
                    res = (nums2[ind2] + nums2[ind2+1]) / 2.0;
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {1,2};
    vector<int> v2 = {3,4};
    printf("%.1f\n",s.findMedianSortedArrays(v1,v2));
}