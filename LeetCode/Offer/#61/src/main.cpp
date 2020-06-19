// #面试题61. 扑克牌中的顺子
// 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，
// 可以看成任意数字。A 不能视为 14。
// 数组的数取值为 [0, 13]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 意思除了0任意变换，其他的数字都是普通的
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int zeros = 0;
        for (int i = 0; i < nums.size()-1; i++)
            if (nums[i] == 0)
                zeros++;
            // 与下一个相等，则不能补救
            else if (nums[i] == nums[i+1])
                return false;
            // 差值 >= 1 判断zeros够不够用
            else if ((zeros -= (nums[i+1] - nums[i] - 1)) < 0)
                return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3,4,5};
    printf("%d\n", s.isStraight(v));
}