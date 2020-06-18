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
};

int main()
{
    Solution s;
    printf("%s\n",s.reverseWords("  hello world!  ").c_str());
}