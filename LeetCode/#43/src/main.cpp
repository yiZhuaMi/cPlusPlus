// #43. 字符串相乘
// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
// num1 和 num2 的长度小于110。
// num1 和 num2 只包含数字 0-9。
// num1 和 num2 均不以零开头，除非是数字 0 本身。
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // num1的每一位都与num2的每一位相乘，余数填+=当前位，进位填前一位。
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return "";
        if ((!num1.empty() && num1[0] == '0') || (!num2.empty() && num2[0] == '0'))
            return "0";
        string res(num1.size() + num2.size(),'0');// 结果的最大位数为位数相加
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int tmp = (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = tmp % 10 + '0';// 当前位
                res[i+j] += tmp / 10;// 前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }
        for (int i = 0; i < res.size(); i++)
            if (res[i] != '0')// 去除前面的0
                return res.substr(i);
        return "0";    
    }
};

int main()
{
    Solution s;
    printf("%s\n",s.multiply("2","3").c_str());
}