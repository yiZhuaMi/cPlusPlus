// #面试题30. 包含min函数的栈
// 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
// 调用 min、push 及 pop 的时间复杂度都是 O(1)。

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> ass;// 辅助栈：维护输入的非严格递减序列!!!!!!!!!!!!
    // 这样辅助栈ass的栈顶永远都是当前栈s中最小的。
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        s.push(x);
        if (ass.empty() || x <= ass.top())
            ass.push(x);// 辅助栈：维护输入的非严格递减序列!!!!!!!!!!!!        
    }
    
    // 难点在于O(1)的min操作，只通过一个最小值无法对付最小值被pop的情况
    void pop() {
        if (ass.top() == s.top())
            ass.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return ass.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */