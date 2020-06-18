// #面试题31. 栈的压入、弹出序列
// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 
// 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) 
            return false;
        if (pushed.size() == 0) 
            return true;
        stack<int> s;
        int i = 0;
        for (auto c : pushed)
        {
            s.push(c);
            while (!s.empty() && s.top() == popped[i])
            {
                s.pop();
                i++;
            }
        }
        return s.empty();// 全部push过后 出来应该s是空的 因为正确的情况会依次pop
    }
};

int main()
{
    Solution s;
    // vector<int> v1 = {1,2,3,4,5}, v2 = {4,3,5,1,2};
    vector<int> v1 = {1,0}, v2 = {1,0};
    cout<<s.validateStackSequences(v1,v2);
}