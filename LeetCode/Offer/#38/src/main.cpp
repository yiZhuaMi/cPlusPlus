// #面试题38 字符串的排列
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
// 输入：s = "abc"
// 输出：["abc","acb","bac","bca","cab","cba"]
// 1 <= s 的长度 <= 8

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> res;
    set<string> se;
    vector<string> permutation(string s) {
        vector<int> used(s.size());
        string line;
        dfs(s,line,used);
        return res;
    }

    void dfs(string s, string& line, vector<int>& used)
    {
        // 复习：排列组合+去重
        if (line.length() == s.length() && se.find(line) == se.end())
        {
            res.push_back(line);
            se.insert(line);
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (used[i] == 0)
            {
                used[i] = 1;
                line.push_back(s[i]);
                dfs(s,line,used);
                line.pop_back();
                used[i] = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    s.permutation("aab");
}