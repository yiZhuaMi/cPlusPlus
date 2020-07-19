// #201 数字范围按位与
// 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

// 示例 1: 

// 输入: [5,7]
// 输出: 4
// 示例 2:

// 输入: [0,1]
// 输出: 0

#include <iostream>
using namespace std;

class Solution {
public:
    // 0 与谁与都为 0
    // 因为 只要有一个0，那么无论有多少个 1都是 0
    // 比如：从 5到 7
    // 5:0 1 0 1
    // 6:0 1 1 0
    // 7:0 1 1 1
    // ---------
    //   0 1 0 0
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        // 相等时都等于1 右边相与的结果都是0
        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            res++;
        }
        // 所以最后将m左移res
        return m << res;
    }
};

int main()
{
    Solution s;
    s.rangeBitwiseAnd(5,7);
}