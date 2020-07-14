// #283. 移动零
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 示例:
// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 说明:
// 必须在原数组上操作，不能拷贝额外的数组。
// 尽量减少操作次数。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 快排思想
    void moveZeroes2(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int p_zero = -1, p_num = -1;
        while (p_zero + 1 < nums.size() && p_num + 1 < nums.size())
        {
            while (p_zero + 1 < nums.size() && nums[++p_zero] != 0) {}
            // 从0的后面找非0
            p_num = p_zero;
            while (p_num + 1 < nums.size() && nums[++p_num] == 0) {}
            
            if (nums[p_zero] == 0 && nums[p_num] != 0)
            {
                int tmp = nums[p_num];
                nums[p_num] = nums[p_zero];
                nums[p_zero] = tmp;
            }
        }
    }

    // 冒泡思想
    void moveZeroes3(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                // 从i+1开始找，找到第一个不为0的
                int j = i+1;
                while (j < nums.size() && nums[j] == 0)
                    j++;
                if (j < nums.size())
                {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
                else
                    break;
                
            }   
        }
    }

    // 快慢指针
    // 相当于把非0的填入另一个数组，只是这里省去了额外的数组，直接填到nums本身
    void moveZeroes(vector<int>& nums) {
        int fast = 0, low = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != 0)
            {
                nums[low++] = nums[fast];// 把非0填到low
            }
            fast++;
        }
        // 最后的要填充0
        while (low < nums.size())
            nums[low++] = 0;     
    }
};

int main()
{
    Solution s;
    vector<int> v = {4,2,4,0,0,3,0,5,1,0};
    // vector<int> v = {0,1,0,3,12};
    s.moveZeroes(v);
}