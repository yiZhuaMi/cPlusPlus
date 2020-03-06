//#28.实现strStr()函数

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.length() == 0)
            return 0;
        if (needle.length() > haystack.length())
            return -1;
        for (size_t i = 0; i < haystack.length(); i++)
        {
            int ind = 0, j = i;
            while (ind < needle.length())
                if (needle[ind] == haystack[j])
                {
                    ind++;
                    j++;
                    if (ind == needle.length())
                        return j - ind;                    
                }
                else
                    break;
        }
        return -1;
    }
};

int main()
{
    string haystack = "mississippi";
    string needle = "issip";
    Solution s;
    printf("%d\n",s.strStr(haystack,needle));
}