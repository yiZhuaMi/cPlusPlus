// 415 字符串相加
// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
// 注意：
// num1 和num2 的长度都小于 5100.
// num1 和num2 都只包含数字 0-9.
// num1 和num2 都不包含任何前导零。
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return num1.empty() ? num2 : num1;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string res = "";
        int ind = 0, addition = 0;
        while (ind < num1.size() || ind < num2.size())
        {
            int a =  ind < num1.size() ? num1[ind] - '0' : 0;
            int b =  ind < num2.size() ? num2[ind] - '0' : 0;
            int n = a + b + addition;
            res += to_string(n % 10);
            addition = n / 10;// 计算addtion的和也要算上一次的addition
            ind++;
        }
        // 最后一次加法也可能进位 出循环要检查
        if (addition)
            res += addition + '0';
        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
    Solution s;
    s.addStrings("9","99");
}