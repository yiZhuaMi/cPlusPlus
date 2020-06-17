// #面试题50 第一个只出现一次的字符
// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。



#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        map<char,int> m;
        for (auto c : s)
            m[c] ++;
        for (auto c : s)
            if (m[c] == 1)
                return c;
        return ' ';
    }
};

int main()
{
    Solution s;
    // printf("%c",s.firstUniqChar("abaccdeff"));
    printf("%c",s.firstUniqChar("wq"));
}