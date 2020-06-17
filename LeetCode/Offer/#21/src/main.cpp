// #面试题21 调整数组顺序使奇数位于偶数前面
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，
// 所有偶数位于数组的后半部分。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums;
        int left = 0, right = nums.size() - 1;// 快排思想：left找左边的偶数 right找右边的奇数
        while (left < right)
        {
            while (left < right && nums[left] % 2 == 1)
                left++;
            while (left < right && nums[right] % 2 == 0)
                right--;
            int tmp = nums[right];
            nums[right] = nums[left];
            nums[left] = tmp;
        }
        return nums;
    }
};

int main()
{   
    Solution s;
    vector<int> in = {};
    vector<int> v = s.exchange(in);

    printf("[%d,",v[0]);
    for (size_t i = 1; i < v.size()-1; i++)
    {
        printf("%d,",v[i]);
    }
    printf("%d]\n",v[v.size()-1]);
}