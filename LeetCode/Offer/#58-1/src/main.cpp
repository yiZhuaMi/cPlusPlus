// #面试题58 - I. 翻转单词顺序
// 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string word = "";
        for (auto c : s)
        {
            if (c == ' ')
            {
                if (!word.empty())
                {
                    v.push_back(word);
                    word.clear();
                }
                continue;
            }
            word.push_back(c);            
        }
        if (!word.empty())
            v.push_back(word);

        for (auto str : v)
            printf("size:%d %s\n",v.size(),str.c_str());


        string res;
        for (int i = v.size()-1; i >= 0; i--)
        {
            res += v[i];
            if (i != 0)
                res += " ";
        }
        return res;
    }

    // 没有处理多余空格
    string reverseWords2(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right)
        {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
        for (left = 0, right = 0; right < s.length();)
        {
            if (right + 1 >= s.length() || s[right + 1] == ' ')
            {
                int r = right;
                while (left < right)
                {
                    int tmp = s[left];
                    s[left++] = s[right];
                    s[right--] = tmp;
                }
                right = r + 2;
                left = r + 2;
            }
            else
            {
                right++;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    printf("%s\n",s.reverseWords2("the sky is blue").c_str());
}