//#8 字符串转换整数 (atoi)
// 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
// 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：
// 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
// 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
// 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。
// 在任何情况下，若函数不能进行有效的转换时，请返回 0 。
// 提示：
// 本题中的空白字符只包括空格字符 ' ' 。
// 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int ind = 0; // 指向字符串的指针
        int len = str.length();
        // 去掉一开始的所有空格
        while (ind < len && str[ind] == ' ')
            ind++;
        // 全是空格 或者 第一个非空（空格）字符既不是数字也不是正负号
        if (ind >= len || (str[ind] != '+' && str[ind] != '-' && str[ind] < '0' && '9' < str[ind]))
            return 0;
        // 保存符号
        int sign = 1;
        // 如果第一个非空是正负号
        if (str[ind] == '+')
        {
            ind++;
        }
        else if (str[ind] == '-')
        {
            sign = -1;
            ind++;
        }
        // 假定遇到正负号的后一个是数字
        int res = 0;
        while (ind < len && isdigit(str[ind]))
        {
            int cur = str[ind] - '0';
            // 因为下面res要*10，所以用 INT32_MAX/10 来比较现在的res
            // 2147483647 / 10 = 214748364
            if (sign == 1 && (res > INT32_MAX / 10 || (res == INT32_MAX / 10 && cur >= 7)))
                return INT32_MAX;
            // -2147483648 / -10 = 214748364
            else if (res > INT32_MIN / -10 || (res == INT32_MIN / -10 && cur >= 8))
                return INT32_MIN;                
            res = res * 10 + cur;
            ind++;
        }
        return sign * res;
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.myAtoi("0-1"));
}