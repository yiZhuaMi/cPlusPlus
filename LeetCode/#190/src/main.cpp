// #190 颠倒二进制位
// 颠倒给定的 32 位无符号整数的二进制位。
// 示例 1：
// 输入: 00000010100101000001111010011100
// 输出: 00111001011110000010100101000000
// 解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
//      因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 32;
        // 移动32次
        while (i--)
        {
            // res左移／乘2
            res <<= 1;
            // 加上个位
            res += n & 1;
            // n右移／除2
            n >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3,3};
}