//#13.罗马数字转整数

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            if(s[i] == 'I')
            {
                if ( i != s.length()-1 && s[i+1] == 'V')
                {
                    num += 4;
                    i++;
                }
                else if (i != s.length()-1 && s[i+1] == 'X')
                {
                    num += 9;
                    i++;
                }
                else
                    num += 1;
            }
            else if (s[i] == 'X')
            {
                if ( i != s.length()-1 && s[i+1] == 'L')
                {
                    num += 40;
                    i++;
                }
                else if (i != s.length()-1 && s[i+1] == 'C')
                {
                    num += 90;
                    i++;
                }                
                else
                    num += 10;
            }
            else if (s[i] == 'C')
            {
                if ( i != s.length()-1 && s[i+1] == 'D')
                {
                    num += 400;
                    i++;
                }
                else if (i != s.length()-1 && s[i+1] == 'M')
                {
                    num += 900;
                    i++;
                }
                else
                    num += 100;
            }
            else if(s[i] == 'V')
                num += 5;
            else if(s[i] == 'L')
                num += 50;
            else if(s[i] == 'D')
                num += 500;
            else if(s[i] == 'M')
                num += 1000;
            else
                printf("invalid input\n");
        }
        return num;
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.romanToInt("XXVII"));
}