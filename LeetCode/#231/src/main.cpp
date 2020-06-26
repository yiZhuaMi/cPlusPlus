// #231 2的幂
// 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    // 二分法 一次性双百！！！
    bool isPowerOfTwo(int n) {
        if (n == 1 || n == 2)
            return true;
        if (n <= 0)
            return false;
        int left = 2, right = 32;// left right 分别代表幂数 32位机器最大整数2^32次方
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (pow(2,mid) > n)
                right = mid - 1;
            else if (pow(2,mid) < n)
                left = mid + 1;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    printf("%d\n", s.isPowerOfTwo(4));
}