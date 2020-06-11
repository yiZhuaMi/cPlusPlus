//#29 两数相除
// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
// 返回被除数 dividend 除以除数 divisor 得到的商。
// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
// 被除数和除数均为 32 位有符号整数。
// 除数不为 0。
// 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        int ans = 0;
        int sign1 = dividend > 0 ? 1 : -1;
        int sign2 = divisor > 0 ? 1 : -1;
        dividend *= sign1;
        divisor *= sign2;
        while (dividend >= divisor)
        {
            dividend -= divisor;
            ans++;
        }
        return sign1 * sign2 * ans;
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.divide(INT32_MIN,-1));
}