//#面试题3 数组中重复的数字
// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，
// 但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
// 鸽巢原理,原地置换
// 因为出现的元素值 < nums.size(); 所以我们可以将见到的元素 放到索引的位置，
// 如果交换时，发现索引处已存在该元素，则重复 O(N) 空间O(1)


// nums[i]：待换位数字
// i：坑位
// nums[nums[i]]：nums[i]应该去的地方

    int findRepeatNumber2(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++)
            // 复习：注意这个while 遍历nums[i]
            while (nums[i] != i)// nums[i]和坑位不匹配 相等则是已经对位的
            {
                if (nums[nums[i]] == nums[i])// nums[i]对应的坑已经被重复的数占了
                    return nums[i];
                else// 其他的数占了nums[i]的坑 则交换
                {
                    int tmp = nums[i];
                    nums[i] = nums[nums[i]];
                    nums[tmp] = tmp;
                }
            }
        return -1;
    }

    int findRepeatNumber(vector<int>& nums) {
        set<int> s;
        for (auto n : nums) 
            if (s.count(n))
                return n;
            else
                s.insert(n);
        return -1;        
    }

};

int main()
{   
    vector<int> v = {2, 3, 1, 0, 2, 5, 3};
    Solution s;
    printf("%d\n",s.findRepeatNumber(v));
}