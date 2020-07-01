// #编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
// 示例 1:
// 输入: "hello"
// 输出: "holle"

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    void swap(char &a, char &b)
    {
        char tmp = a;
        a = b;
        b = tmp;
    }

    string reverseVowels2(string s) {
        int left = 0, right = s.length() - 1;
        set<char> char_set = {'a','A','e','E','i','I','o','O','u','U'};
        while (left < right)
        {
            while (left < right && char_set.find(s[right]) == char_set.end())
            {
                right--;
            }
            while (left < right && char_set.find(s[left]) == char_set.end())
            {
                left++;
            }
            swap(s[left++],s[right--]);
        }
        return s;
    }

    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        // string作为顺序容器也可以用find ！！！！！！！！ 没找到返回-1
        string char_set = "aAeEiIoOuU";
        while (left < right)
        {
            while (left < right && char_set.find(s[right]) == -1)
            {
                right--;
            }
            while (left < right && char_set.find(s[left]) == -1)
            {
                left++;
            }
            swap(s[left++],s[right--]);
        }
        return s;
    }
};

int main()
{
    Solution s;
    printf("%s\n",s.reverseVowels("hello").c_str());
}