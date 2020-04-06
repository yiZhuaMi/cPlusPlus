//#面试题15 二进制中1的个数

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while (n != 0)
        {
            if (n % 2 == 1)
                num++;
            n /= 2;
        }
        return num;
    }
    int hammingWeight2(uint32_t n) {
        int num = 0;
        while (n)
        {
            num += n & 1;
            n >>= 1;
        }
        return num;
    }
};

int main()
{   
    Solution s;
    // uint32_t n = 3;
    uint32_t n = (uint32_t)00000000000000000000000000001011;
    printf("%d",s.hammingWeight2(n));
}