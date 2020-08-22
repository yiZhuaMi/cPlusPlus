//#7.整数反转
//INT_MAX INT_MIN

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse1(int x) {
        long a = pow(2,31),b = a - 1,r = 0;
        if(x < 0 && abs(long(x)) == a) return 0;
        int ind = 0;
        string str;
        while(x / 10 != 0){
            str.append(to_string(abs(x % 10)));
            x /= 10;
            ind++;
        }
        str.append(to_string(abs(x)));
        r = atol(str.c_str());
        if(x < 0) r = -r;
        if(r > b || r < -1 * a) r = 0;
        return r;
    }

    int reverse3(int x) {
        long y = 0;
        while (x != 0)
        {
            y = x % 10 + y * 10;
            x /= 10;
        }
        return y > INT32_MAX || y < INT32_MIN ? 0 : y;
    }

    int reverse(int x) {
        // 必须先处理INT32_MIN 下面处理不了
        if (x == INT32_MIN)
            return 0;
        int sign = x > 0 ? 1 : -1;
        // 先取绝对值
        int z = x < 0 ? -x : x;
        int y = 0;
        while (z)
        {
            if (sign > 0 && (y > INT32_MAX / 10 || (y == INT32_MAX / 10 && z % 10 >= 7)))
                return 0;
            if (sign < 0 && (y > INT32_MIN / -10 || (y == INT32_MIN / -10 && z % 10 >= 8)))
                return 0;
            y = y * 10 + z % 10;
            z /= 10;
        }
        // 最后加上符号
        return sign * y;
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.reverse(-321));
}