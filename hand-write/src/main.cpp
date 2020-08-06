#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include "unistd.h"

#include "threadpool.h"
#include "syn_queue.h"

using namespace std;

My_queue q;
mutex mutex_t;

void task1(int t_id)
{
    printf("%d start\n",t_id);
    sleep(2);
    printf("%d done\n",t_id);
}

void decrease(int t_id)
{
    while (true)
    {
        mutex_t.lock();
        if (q.empty())
        {
            mutex_t.unlock();
            break;
        }
        else
        {
            printf("%d q.top = %d\n",t_id,q.front());
            q.pop();    
        }
        mutex_t.unlock();
    }
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        q.push(i);
    }
    // thread t1(decrease,"thead 1");
    // thread t2(decrease,"thead 2");
    // t1.join();
    // t2.join();

    function<void(int)> func = decrease;
    ThreadPool pool(5);
    for (int i = 0; i < 6; i++)
    {
        pool.execute(task1);
    }
    sleep(5);
    pool.execute(task1);

    getchar();
}