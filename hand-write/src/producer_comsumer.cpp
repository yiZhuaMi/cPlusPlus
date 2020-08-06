#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "unistd.h"
using namespace std;

queue<int> tasks;
mutex mtx;
condition_variable produce, comsume;
int max_size = 8;

void comsumer()
{
    while (1)
    {
        sleep(1);
        unique_lock<mutex> lk(mtx);
        while (tasks.empty())
        {
            comsume.wait(lk);
        }
        // 消费
        cout<<"-"<<tasks.front()<<endl;
        tasks.pop();
        produce.notify_all();
    }
}

void producer()
{
    while (1)
    {
        sleep(1);
        unique_lock<mutex> lk(mtx);
        while (tasks.size() >= max_size)
        {
            produce.wait(lk);
        }
        // 生产
        static int good = 0;
        cout<<"+"<<++good<<endl;
        tasks.push(good);
        comsume.notify_all();
    }
}

// 实现生产者消费者模式
int main()
{
    thread p1(producer);        
    thread p2(producer);        
    thread c1(comsumer);
    p1.join();
    p2.join();
    c1.join();
}