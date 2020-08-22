//#面试题58-2 左旋转字符串

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseLeftWords2(string s, int n) {
        return s.substr(n,s.length()-n) + s.substr(0,n);
    }

    string reverseLeftWords(string s, int n) {
        int len = n % s.length();
        reverse(s.begin(),s.begin() + len);
        reverse(s.begin() + len,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};

int main()
{
    string str = "lrloseumgh";
    int k = 6;
    Solution s;
    printf("%s\n",s.reverseLeftWords(str,k).c_str());
}