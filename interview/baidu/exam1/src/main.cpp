#include <iostream>
#include <queue>
#include <mutex>
using namespace std;
// 实现阻塞同步队列

class My_queue
{
private:
    mutex mutex_t;
    queue<int> q;

public:
    int front()
    {
        mutex_t.lock();
        int res;
        if (!q.empty())
        {
            res = q.front();
        }
        else
        {
            res = -1;
        }
        mutex_t.unlock();
        return res;
    }

    void push(int val)
    {
        mutex_t.lock();
        q.push(val);
        mutex_t.unlock();
    }

    void pop()
    {
        mutex_t.lock();
        q.pop();
        mutex_t.unlock();
    }
};

int main()
{
    
}