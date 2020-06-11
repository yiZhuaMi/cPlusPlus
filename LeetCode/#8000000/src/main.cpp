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
        if (str.empty() || (str[0] != '-' && str[0] < '0' && str[0] > '9'))
            return 0;
        int start = 0, sign = 1;
        while (str[start] == ' ' || str[start] == '0')//  "0-1" 预期0 结果-1
            start++;
        if (str[start] == '-' || str[start] == '+')
        {
            sign = str[start] == '-' ? -1 : 1;
            start++;
        }    
        if (str[start] < '0' || str[start] > '9')// 符号后面不是数字
            return 0;        
        while (str[start] == '0')
            start++;

        int end = start;// 左闭右开
        while (str[end] >= '0' && str[end] <= '9')
            end++;
        if (end - start > 10)
            return sign > 0 ? INT32_MAX : INT32_MIN;
        int sum = 0;// 绝对值
        for (int i = 0; i < end - start; i++)
        {
            // 改变一下表达式
            // res * 10 + curVal <= MAX，转化一下 res <= (MAX - curVal)/10 !!!!!!!!!!!!
            if (sign < 0 && -sum <= INT32_MIN + (str[end - i - 1] - '0') * pow(10,i))// 只会相等 -2147483648 * -1 = -2147483648 ？？？？？
                return INT32_MIN;
            else if (sign > 0 && sum >= INT32_MAX - (str[end - i - 1] - '0') * pow(10,i))// 大于INT32_MAX会溢出，溢出以后变最小值（负数）
                return INT32_MAX;      
            sum = sum + (str[end - i - 1] - '0') * pow(10,i);// 安全  
        }
        return sign * sum;
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.myAtoi("0-1"));
}