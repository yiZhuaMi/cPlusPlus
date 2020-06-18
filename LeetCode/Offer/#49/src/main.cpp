// #面试题49. 丑数
// 我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
// 我们知道，丑数的排列肯定是1,2,3,4,5,6,8,10.... 然后有一个特点是，任意一个丑数都是由小于
// 它的某一个丑数*2，*3或者*5得到的，那么如何得到所有丑数呢？ 现在假设有3个数组，分别是： 
// A：{1*2，2*2，3*2，4*2，5*2，6*2，8*2，10*2......}
// B：{1*3，2*3，3*3，4*3，5*3，6*3，8*3，10*3......}
// C：{1*5，2*5，3*5，4*5，5*5，6*5，8*5，10*5......}
// 那么所有丑数的排列，必定就是上面ABC3个数组的合并结果然后去重得到的，那么这不就转换成了三个有
// 序数组的无重复元素合并的问题了吗？而这三个数组就刚好是{1,2,3,4,5,6,8,10....}乘以2,3,5得到的。
// 合并有序数组的一个比较好的方法，就是每个数组都对应一个指针，然后比较这些指针所指的数中哪个最
// 小，就将这个数放到结果数组中，然后该指针向后挪一位。

// 然后有一个特点是，任意一个丑数都是由小于它的某一个丑数*2，*3或者*5得到的 -----> 合并三个有序数组并去重
    int nthUglyNumber(int n) {
        vector<int> ugly_nums(1);
        ugly_nums[0] = 1;// 第一个丑数
        int ind_2 = 0,ind_3 = 0,ind_5 = 0;
        while (--n)// 找到第n个丑数
        {
            ugly_nums.push_back(min(ugly_nums[ind_2] * 2, min(ugly_nums[ind_3] * 3, ugly_nums[ind_5] * 5)));
            // 不用else if 为了去重！！！ 可能都是最小的 所以都要移动
            // 加入的==由2乘出的丑数
            if (ugly_nums[ugly_nums.size()-1] == ugly_nums[ind_2] * 2)
                ind_2++;
            // 加入的==由3乘出的丑数
            if (ugly_nums[ugly_nums.size()-1] == ugly_nums[ind_3] * 3)
                ind_3++;
            // 加入的==由5乘出的丑数
            if (ugly_nums[ugly_nums.size()-1] == ugly_nums[ind_5] * 5)
                ind_5++;
        }
        return ugly_nums[ugly_nums.size()-1];
    }
};

int main()
{
    Solution s;
    printf("%d",s.nthUglyNumber(10));
}