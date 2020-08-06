#include <iostream>
#include <queue>
#include <mutex>
using namespace std;
// 实现阻塞同步队列

class My_queue
{
public:
    void push(int val)
    {
        t.lock();
        q.push(val);
        t.unlock();
    }

    int front()
    {
        int res = -1;
        t.lock();
        if (!q.empty())
        {
            res = q.front();
        }
        t.unlock();
        return res;
    }

    void pop()

private:
    queue<int> q;
    mutex t;
};