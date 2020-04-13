//#27 移除元素

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // j指向最后一个!=val的数
        // i遍历每一个数
        int j = -1;
        for (size_t i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[++j] = nums[i];
        return j+1;
    }
};

int main()
{
    vector<int> num = {3,2,2,3};
    Solution s;
    printf("%d\n",s.removeElement(num,3));
}