// #41. 缺失的第一个正数
// 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 原地哈希
    // 原地哈希就相当于，让每个数字n都回到下标为n-1的家里。
    // 而那些没有回到家里的就成了孤魂野鬼流浪在外，他们要么是根本就没有自己的家（数字小于等于0或者大于nums.size()），要么是自己的家被别人占领了（出现了重复）。
    // 这些流浪汉被临时安置在下标为i的空房子里，之所以有空房子是因为房子i的主人i+1失踪了（数字i+1缺失）。
    // 因此通过原地构建哈希让各个数字回家，我们就可以找到原始数组中重复的数字还有消失的数字。
    void swap(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size();)// !!!
        {
            // 确保nums[nums[i]-1]不会越界 是nums[i]作为下标而不是i
            if (nums[i] >= 1 && nums[i] < nums.size() + 1 &&
            // 确保nums[i]要去的下标nums[i]-1处对应的数不正确(没有被另一个自己占用)
                nums[nums[i] - 1] != nums[i])
            {
                swap(nums, nums[i] - 1, i);
            }
            else
                i++;
        }

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1; 

        return nums.size() + 1;// !!!!!!!!!!!
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 0};
    printf("%d\n", s.firstMissingPositive(v));
}