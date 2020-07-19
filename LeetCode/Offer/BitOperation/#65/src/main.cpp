// #面试题65. 不用加减乘除做加法
// 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

#include <iostream>
using namespace std;

class Solution {
public:
    // 二进制
    // 异或运算 ^ ：相当于无进位求和 1 ^ 1 = 0
    // 与运算 & ：相当于求进位数 1 & 1 = 1 但是需要扩大2倍，所以需要左移<<一位：1 & 1 << 1 = 10
    int add2(int a, int b) {
        while (b != 0)// 直到进位数为0
        {
            int tmp = a ^ b;// 无进位求和
            b = (unsigned int)(a & b) << 1;// 进位数 c++不支持负值左移，需要强制转换为无符号数
            a = tmp;    
        }
        return a;
    }
    //  递归 更好理解
    int add(int a, int b) {
        if (b == 0)// 递归结束条件 当进位数等于0，返回无进位和a
            return a;
        // c++不支持负值左移，需要强制转换为无符号数
        return add (a ^ b, (unsigned int)(a & b) << 1);// 由于将无进位和和进位数相加也不能用+法，所以递归
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.add(19,-1));
}