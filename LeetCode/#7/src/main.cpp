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

    int reverse(int x) {
        long y = 0;
        while (x != 0)
        {
            y = x % 10 + y * 10;
            x /= 10;
        }
        return y > INT32_MAX || y < INT32_MIN ? 0 : y;
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.reverse(-2147483648));
}