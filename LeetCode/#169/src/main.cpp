// #169. 多数元素
// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于  n/2  的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 摩尔投票法
    // 从第一个数开始count=1，遇到相同的就加1，遇到不同的就减1，减到0就重新换个数开始计数，总能找到最多的那个
    // 由于众数数量超过一半，所以最终会取胜
    int majorityElement2(vector<int>& nums) {
        int candi, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)// 没有任何人被支持 就去竞选
                candi = nums[i];
            // 投票
            count = candi == nums[i] ? count+1 : count-1;
        }
        return candi;
    }

    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3,3};
    printf("%d\n",s.majorityElement(v));
}