#include <iostream>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <thread>
#include <queue>
using namespace std;

class ThreadPool
{
public:
    ThreadPool() = default;
    ThreadPool(ThreadPool&& other) = default;

    explicit ThreadPool(size_t thread_count) : _data(make_shared<data>())
    {
        for (size_t i = 0; i < thread_count; i++)
        {
            thread([i, pool = _data]
            {
                unique_lock<mutex> lk(pool->_mtx);
                while (true)
                {
                    if (!pool->_tasks.empty())
                    {
                        auto cur = pool->_tasks.front();
                        pool->_tasks.pop();
                        lk.unlock();
                        cur(i);
                        lk.lock();
                    }
                    else if (pool->_is_shutdown)
                    {
                        break;
                    }
                    else
                    {
                        pool->_cond.wait(lk);
                    }
                }
            }).detach();
        }
    }

    ~ThreadPool()
    {
        if ((bool)_data)
        {
            {
                lock_guard<mutex> lk(_data->_mtx);
                _data->_is_shutdown = true;
            }
            _data->_cond.notify_all();
        }
    }

    template <typename F>
    void excute(F&& task)
    {
        {
            lock_guard<mutex> lk(_data->_mtx);
            _data->_tasks.emplace(forward<F>(task));
        }
        _data->_cond.notify_one();
    }

private:
    struct data
    {
        mutex _mtx;
        condition_variable _cond;
        bool _is_shutdown = false;
        queue<function<void(int)>> _tasks;
    };
    shared_ptr<data> _data;
};