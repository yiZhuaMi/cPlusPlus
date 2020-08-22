//#面试题15 二进制中1的个数

#include <iostream>
#include <vector>
#include <string>
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
            n >>= 1;// >>= !!!!!!!! 不是>>!!!!!!!!!
        }
        return num;
    }

    // 10进制转2进制字符串
    string shi2er(int num)
    {
        string res = "";
        while (num > 0)
        {
            res.push_back(num % 2 + '0');
            num /= 2;
        }
        return string(res.rbegin(),res.rend());
    }
};

int main()
{   
    Solution s;
    // uint32_t n = 3;
    uint32_t n = (uint32_t)00000000000000000000000000001011;
    printf("%d\n",s.hammingWeight2(n));
    printf("%s\n",s.shi2er(11).c_str());
}