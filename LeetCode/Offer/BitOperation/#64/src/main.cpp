//#面试题64 求1+2+…+n

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int sumNums(int n) {
        // return (1+n)*n/2;// 不能用乘除法
        return (int)pow(n,2) + n >> 1;//右移一位 -> 除以2
    }
};

int main()
{
    int n = 1;
    Solution s;
    printf("%d\n",s.sumNums(n));
}