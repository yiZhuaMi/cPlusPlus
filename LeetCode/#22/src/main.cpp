// #22 括号生成
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {};
        string line = "(";// 第一个必须是左括号
        int left = n, right = n;// 剩余左右括号
        helper(line,left-1,right);
        return res;
    }
    // 回溯: 加上当前 递归 然后去除当前 返回
    void helper(string line, int left, int right)
    {
        if (right <= 0)
            res.push_back(line);
        else
        {
            if (left <= 0)// 只剩右括号了
            {
                line.push_back(')');
                helper(line,left,right-1);// 只有一种情况无法回溯了
                // line.pop_back();// 回溯
            }
            else// 左右括号都有
            {
                line.push_back('(');// 先添加(
                helper(line,left-1,right);// 递归
                line.pop_back();// 回溯
                
                if (left < right)// 右必须大于左 否则不能添加右括号了
                {
                    line.push_back(')');// 再添加)
                    helper(line,left,right-1);// 递归
                    line.pop_back();// 回溯   
                }
            }
        }
    }
    // 不回溯直接递归
    void helper2(string line, int left, int right)
    {
        if (right <= 0)
            res.push_back(line);
        else
        {
            if (left <= 0)// 只剩右括号了
                helper(line+")",left,right-1);
            else// 左右括号都有
            {
                // 这一步添加(，line是拷贝的，不需要回溯
                helper(line+"(",left-1,right);                
                // 如果符合条件，这一步添加)，line是拷贝的，不需要回溯
                if (left < right)// 右必须大于左 否则不能添加右括号了
                    helper(line+")",left,right-1);// 递归
            }
        }
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for (auto str : ans)
    {
        printf("%s\n",str.c_str());
    }
}