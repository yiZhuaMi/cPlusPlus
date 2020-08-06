#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

mutex mtx;
condition_variable produce;
condition_variable comsume;
queue<int> tasks;
int max_size = 8;

void producer()
{
    while (1)
    {
        unique_lock<mutex> lk(mtx);
        while (tasks.size() >= max_size)
        {
            produce.wait(lk);
        }
        tasks.push(random());
        produce.notify_all();
    }
}

void comsumer()
{
    while (1)
    {
        unique_lock<mutex> lk(mtx);
        while (tasks.empty())
        {
            comsume.wait(lk);
        }
        tasks.pop();
        comsume.notify_all();
    }
}