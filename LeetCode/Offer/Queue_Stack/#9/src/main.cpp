//#面试题9 用两个栈实现队列

#include <iostream>
#include <stack>
using namespace std;

class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int size = 0;

    CQueue() {
    
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int r;
        if (s1.empty() && s2.empty())
        {
            return -1;
        }
        // 复习：必须s2空才能将s1转移到s2，否则破坏先进先出
        if (s2.empty())// s1非空
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        r = s2.top();
        s2.pop();// delete
        return r;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */