//#1.两数之和
//用break会终止内层循环

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)//直接i+1
            {
                if(nums.at(i) + nums.at(j) == target)
                {
                    return {i,j};//无需新声明vector
                }
            }    
        }
        return {0};
    }
};

int main()
{
    vector<int>nums {-3,4,3,90};
    int target = 0;
    Solution s;
    nums = s.twoSum(nums,target);
    printf("[%d, %d]\n",nums.at(0),nums.at(1));
}