// #32 最长有效括号
// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的!!!子串!!!的长度。

// 示例 1:

// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
// 示例 2:

// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // 存放下标
        stack<int> st;
        // 向栈中预置一个-1，将计算长度的方式转化成")"的下标减去 出栈后 栈顶元素的下标
        st.push(-1);
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                char a = st.top();
                st.pop();
                // 如栈空，则注入新的i作为预置下标
                if (st.empty())
                    st.push(i);
                res = max(res,i - st.top());
            }            
        }
        return res;
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.longestValidParentheses("()(())"));
}