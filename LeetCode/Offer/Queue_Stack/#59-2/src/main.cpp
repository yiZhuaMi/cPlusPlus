// #面试题59 - II. 队列的最大值
// 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数
// max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
// 若队列为空，pop_front 和 max_value 需要返回 -1

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// class MaxQueue {
// private:
//     queue<int> q;
//     stack<int> s;// 辅助栈：用来存q的非严格递增序列，栈顶最大
// public:
//     MaxQueue() {

//     }
    
//     int max_value() {
//         return !q.empty() && !s.empty() ? s.top() : -1;
//     }
    

//     // 这里不能用栈来辅助队列，不同于"min函数栈"那道题中，两个都是栈，都是先进后出
//     // 不会出现辅助栈中唯一的最值和对应的主栈中的值被弹出后，主栈非空而辅助栈为空的情况
//     // 但是本题是队列，与辅助栈的弹出方向相反，会出现以下情况
//     // 辅助栈为了队头最大值，舍弃后面元素，此时队头和栈中唯一元素同时被弹出，导致辅助栈空而队列非空。
//     // q头{3,2,1}q尾     s底{3}s顶
//     // pop
//     // q头{2,1}q尾       s底{ }s顶

//     void push_back(int value) {
//         q.push(value);
//         if (s.empty() || value >= s.top())// 栈低 <= 栈顶
//             s.push(value);
//     }
    
//     int pop_front() {
//         if (q.empty())
//             return -1;
//         if (q.front() == s.top())// 出队元素=栈顶元素=最大元素
//             s.pop();
//         int res = q.front();
//         q.pop();
//         return res;
//     }
// };
class MaxQueue {
private:
    queue<int> q;
    deque<int> dq;// 需要pop_back 辅助双端队列 维护从尾到头的递增序列
public:
    MaxQueue() {

    }
    
    int max_value() {
        return !q.empty() && !dq.empty() ? dq.front() : -1;
    }
    
    void push_back(int value) {
        q.push(value);
        // dq非空，若value比队尾大，则删除队尾；构造dq从头到尾（非严格）递减的序列
        while (!dq.empty() && dq.back() < value)
            dq.pop_back();
        dq.push_back(value);
    }

    // void push_back(int value) {
    //     q.push(value);
    //     if (dq.empty())
    //         dq.push_back(value);
    //     // dq非空，若队尾比value小，则删除队尾，构造非严格递增的序列
    //     else
    //     {
    //         while (dq.back() < value)// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //             dq.pop_back();// 错误写法：dq弹出一直到空时，条件语句越界 !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //         dq.push_back(value);// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //     }
    // }
    
    int pop_front() {
        if (q.empty())
            return -1;
        if (q.front() == dq.front())
            dq.pop_front();
        int res = q.front();
        q.pop();
        return res;
    }
};

int main()
{

}