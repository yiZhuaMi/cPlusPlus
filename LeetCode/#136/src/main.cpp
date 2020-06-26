// #136. 只出现一次的数字
// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int singleNumber2(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 && nums[i] != nums[i+1])
                return nums[i];
            if (i == nums.size() - 1 && nums[i] != nums[i-1])
                return nums[i];
            if (i != 0 && i != nums.size() - 1 && nums[i] != nums[i-1] && nums[i] != nums[i+1])
                return nums[i];
        }
        return -1;
    }

    // 异或
    // a ^ a = 0
    // a ^ 0 = a
    // a ^ b = b ^ a
    // a ^ b ^ c = a ^ (b ^ c)
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto n : nums)
            res ^= n;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {4,1,2,1,2};
    printf("%d ",s.singleNumber(v));
}