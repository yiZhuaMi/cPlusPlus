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
    vector<string> permutation(string s) {
        vector<string> res;
        string one_ans = "";
        vector<bool> used(s.length(),false);
        set<string> set;
        dfs(s,one_ans,res,used,set,true);
        return res;
    }

    // 要去重！！！！！！！
    void dfs(const string &s, string &one_ans, vector<string> &res, vector<bool> &used, set<string> &set, bool top)
    {
        if (one_ans.length() == s.length() && set.find(one_ans) == set.end())
        {
            res.push_back(one_ans);
            set.insert(one_ans);
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (i < s.length() - 1 && top && s[i] == s[i+1])// 处于顶层递归，也就是排列第一个字符，与下一个相同 则剪枝
                continue;
            if (!used[i])
            {
                one_ans.push_back(s[i]);
                used[i] = true;
                dfs(s,one_ans,res,used,set,false);
                one_ans.pop_back();
                used[i] = false;
            }
        }
    }
};

int main()
{
    Solution s;
    s.permutation("aab");
}