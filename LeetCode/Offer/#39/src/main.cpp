//#面试题39 数组中出现次数超过一半的数字

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

static void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

class Solution {
public:
    // 先排序 返回中位数 时间复杂度:O(n^2) 空间复杂度:O(1)
    int majorityElement2(vector<int>& nums) {
        int tmp = 0;
        for (size_t i = 0; i < nums.size()-1; i++)// 已经排列好的个数
        {
            for (size_t j = 0; j < nums.size()-1-i; j++)
            {
                if (nums[j] > nums[j+1])
                {
                    tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                }
            }
        }
        return nums[nums.size()/2];
    }

    // 先排序 返回中位数 时间复杂度:O(nlog2(n)) 空间复杂度:O(1)
    int majorityElement3(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        for (auto n : nums)
            printf("[%d]",n);
        return nums[nums.size()/2];
    }

    int partiton(vector<int>& nums, int left, int right)
    {
        int key = left;
        while (left < right)
        {
            while (left < right && nums[key] <= nums[right])// 先操作右指针！！！！！！！！ 不知道为啥先左会第一个无序
            {
                right--;
            }
            while (left < right && nums[left] <= nums[key])
            {
                left++;
            }
            swap(nums[left],nums[right]);
        }
        swap(nums[key],nums[left]);
        return left;// 返回key值最后的索引
    }

    void quickSort(vector<int>& nums, int left, int right)
    {
        // if (nums.size() <= 1 || left >= right)
        //     return;
        if (left < right)
        {
            int key = partiton(nums,left,right);
            quickSort(nums,left,key-1);// 不再是0和size-1 而是传进来的left right！！！！
            quickSort(nums,key+1,right);
        }
    }

    int majorityElement(vector<int>& nums) {
        int x = 0, vote = 0;
        for (auto n : nums)
        {
            if (vote == 0) // 票数为0才更新假设
                x = n;// 假设n是众数x
            vote += (n == x ? 1 : -1);// 当n是众数 票数加1 否则减1
        }
        return x;
    }
};

int main()
{
    Solution s;
    vector<int> v = {2,2,1,1,1,2,2};
    // vector<int> v = {1};
    printf("%d",s.majorityElement(v));
}