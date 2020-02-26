//#26.删除排序数组中的重复项

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
        
    //     if (nums.size() <= 1)
    //         return nums.size();
    //     int pre_num = nums[0];
    //     int len = nums.size();
    //     for (size_t i = 1; i < nums.size(); i++)
    //     {
    //         if (nums[i] == pre_num)
    //             nums[i] = nums[0]-1;
    //         else
    //             pre_num = nums[i];
    //     }
    //     for (size_t i = 0; i < nums.size(); i++)
    //     {
    //         if (nums[i] == nums[0]-1 || nums[i] == nums[0]-2)
    //         {
    //             if (nums[i] == nums[0]-1)
    //                 len--;   
    //             for (size_t j = i+1; j < nums.size(); j++)
    //             {
    //                 if (nums[j] != nums[0]-1 && nums[j] != nums[0]-2)
    //                 {
    //                     nums[i] = nums[j];
    //                     nums[j] = nums[0]-2;
    //                     break;    
    //                 }
    //             }
    //         }
    //     }
    //     return len;
    // }

    // 双指针法
    // 数组完成排序后 我们可以放置两个指针i和j 其中i是慢指针 而j是快指针 只要nums[i]=nums[j] 我们就增加j以跳过重复项
    // 当我们遇到 nums[j]!=nums[j] 跳过重复项的运行已经结束，因此我们必须把它nums[j]的值复制到nums[i+1] 然后递增i
    // 接着我们将再次重复相同的过程 直到j到达数组的末尾为止

    // j指向排好序的最后一个
    // 当找到与j不相等的j+1=i
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) 
            return nums.size();
        int j = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[j] != nums[i]) 
                nums[++j] = nums[i];
        return ++j;
    }
};

int main()
{
    vector<int> num = {0,1,55,55,789,1001,1001,1001,1001,9999,9999};
    // vector<int> num = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    int len = s.removeDuplicates(num);
    printf("%d\n",len);
    for (int i = 0; i < len; i++) {
        printf("%d ",num[i]);
    }
    printf("\n");
}