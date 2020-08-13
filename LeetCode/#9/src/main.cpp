//#9.回文数
//形参是int 操作的时候最好用long

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    bool isPalindrome(int x) {
        string in = to_string(x),out = in;
        reverse(in.begin(),in.end());
        return in.compare(out) ? false : true;
    }

    bool isPalindrome2(int x) {
        if(x < 0)
            return false;
        else if (x ==0)
            return true;
        else
        {
            long y = 0, z = long(x);// y就是将x位数反过来的数 long!!!!!!!!!!!!!!!!
            while (x > 0)
            {
                // x%10得到x最右一位，+y*10使得原来靠右的现在靠左
                y = x % 10 + y * 10;//用int会溢出
                x /= 10;
            }
            return y == z ? true : false;
        }
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.isPalindrome(12321));
}