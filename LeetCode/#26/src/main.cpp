//#26.删除排序数组中的重复项

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() <= 1)
            return nums.size();

        int pre_num = nums[0];
        int len = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] == pre_num)
            {
                for (size_t j = i; j < nums.size()-1; j++)
                {
                    nums[j] = nums[j+1];
                }
                
            }
            else
            {
                len++;
            }
            
            pre_num = nums[i];
        }
        
        return len;
    }
};

int main()
{
    vector<int> num = {0,1,2,2,3};
    Solution s;
    printf("%d\n",s.removeDuplicates(num));
    
}