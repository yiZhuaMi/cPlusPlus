#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <queue>
using namespace std;

// 实现线程池
class ThreadPool
{
public:
    ThreadPool() = default;
    ThreadPool(ThreadPool&&) = default;

    explicit ThreadPool(size_t thread_count) : _data(make_shared<data>())
    {
        for (size_t i = 0; i < thread_count; i++)
        {
            // 拷贝的是 shared_ptr 而不是其实际指向的data对象，一个线程池只有一个data对象
            thread([pool = _data, i]
            {
                int t_id = i;
                // unique_lock在构造函数中加锁，析构函数中解锁
                unique_lock<mutex> lk(pool->_mtx);// 先锁，再while
                while (true)
                {
                    // 任务队列非空
                    if (!pool->_tasks.empty())
                    {
                        printf("%d get task\n",t_id);
                        auto cur = std::move(pool->_tasks.front());
                        pool->_tasks.pop();
                        lk.unlock();// 取出任务就释放锁，执行任务的时候是没有占有锁的
                        printf("%d cur...\n",t_id);
                        cur(t_id);
                        lk.lock();// 争抢锁，任务执行完阻塞在请求锁，以便下一次检查
                    }
                    // 关闭线程池
                    else if (pool->_shutdown)
                    {
                        printf("%d shutdown!\n",t_id);
                        break;
                    }
                    // 睡眠在条件变量的等待队列中，释放锁； 等待execute往队列中插入函数，返回前必须先请求到锁
                    else
                    {
                        printf("%d wait\n",t_id);
                        pool->_cond.wait(lk);// 争抢锁
                    }
                }
            // 分离子线程，不必再与主线程汇合
            }).detach();
        }
    }

    ~ThreadPool()
    {
        printf("~ThreadPool\n");
        if ((bool)_data)
        {
            {
                // lock_guard在构造函数中加锁，析构函数中解锁
                lock_guard<mutex> lk(_data->_mtx);
                printf("_shutdown = true\n");
                _data->_shutdown = true;
            }
            // 将所有线程唤醒，有任务就执行，没有任务就全break了
            printf("notify_all\n");
            _data->_cond.notify_all();
        }
    }

    // 执行任务的接口
    template <typename F>
    void execute(F&& task)// 必须是右值引用F&& 用左／右值初始化，变成左／右值引用
    {
        {
            lock_guard<mutex> lk(_data->_mtx);
            printf("added task\n");
            _data->_tasks.emplace(forward<F>(task));// 若task用右值初始化的，那就转发出右值
        }
        // 先释放锁再通知，否则工作线程抢不到锁，导致从cond的队列中一醒来又睡在mtx的队列中
        printf("notify_one\n");
        _data->_cond.notify_one();
    }

private:
    struct data
    {
        mutex _mtx;
        condition_variable _cond;
        bool _shutdown = false;
        // function<void()>
        // 一个可调用对象的容器的类型，用以存储任何可以以fun()的形式调用且返回类型为void的对象（函数，lambda函数，
        // 由std::bind产生的对象，以及任何其他重载了void operator()()的类），而不用关心这个对象实际是什么
        queue<function<void(int)>> _tasks;
    };
    shared_ptr<data> _data;
};