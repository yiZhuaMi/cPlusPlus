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
};

int main()
{
    Solution s;
    printf("%d\n",s.isValid("){"));
}