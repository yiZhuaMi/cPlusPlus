//#面试题5 替换空格
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string str;
        for (auto c : s)
            if (c == ' ')
            {
                str.push_back('%');
                str.push_back('2');
                str.push_back('0');
            }
            else
                str.push_back(c);            
            
        return str;
    }
};

int main()
{   
    string str = "We are happy.";
    Solution s;
    printf("%s\n",s.replaceSpace(str).c_str());
}