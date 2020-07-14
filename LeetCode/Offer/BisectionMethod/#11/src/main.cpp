//#面试题11 旋转数组的最小数字
// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，
// 数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minArray2(vector<int>& numbers) {   
        for (int i = 1; i < numbers.size(); i++)
        {
            if (numbers[i-1] > numbers[i])
                return numbers[i];           
        }
        return numbers[0];// 全部递增 || size<=1 返回第一个
    }
    // {4,5,6,1,2,3,4}
    int minArray(vector<int>& numbers) {   
        if (numbers.empty())
            return 0;
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;// mid >= left
            if (numbers[mid] < numbers[right])// 说明最小值在[left,mid]之间
            {
                right = mid;
            }
            else if (numbers[mid] == numbers[right])// 有相同的两个值 则至少也可以排除right (不能直接right=mid)
            {
                right--;
            }
            else// numbers[mid] > numbers[right] 说明最小值在[mid+1,right]之间
            {
                left = mid + 1;
            }   
        }
        return numbers[left];        
    }
};

int main()
{   
    Solution s;
    vector<int> v = {2,2,2,3,1};
    s.minArray(v);
}