//#20.有效的括号
// st.top();           //返回栈顶元素, 但不删除该元素
// st.pop();           //弹出栈顶元素, 但不返回其值
// pop top 前要判空
// &&优先于||

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // 只包含括号
    bool isValid(string s) {
        stack<char> st;
        if(s.size()%2 != 0) 
            return false;
        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (!st.empty() && (s[i] == st.top()+1 || s[i] == st.top()+2))//aissc
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty() ? true : false;
    }

    // 考虑其他字符
    bool isV(string s) {
        if (s.empty())
            return true;
        stack<char> st;
        for (auto c : s)
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (c == ')' || c == '}' || c == ']')
            {
                if (st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if ((c == ')' && ch != c - 1) || ((c == '}' || c == ']') && ch != c - 2))
                    return false;
            }
        if (!st.empty())
            return false;
        
        return true;
    }
};

int main()
{
    // printf("%d %d %d %d %d %d\n",'(',')','{','}','[',']');
    Solution s;
    printf("%d\n",s.isValid("()(*{})"));
}