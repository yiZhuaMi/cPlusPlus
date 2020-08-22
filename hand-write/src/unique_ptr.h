#include <iostream>
using namespace std;

// 实现unique_ptr
template <typename T>
class unique_ptr
{
public:
    unique_ptr(T* ptr) : _ptr(ptr) {}
    ~unique_ptr() 
    {
        if(_ptr != nullptr)
            delete _ptr; 
    }

    // 禁用拷贝构造和拷贝赋值
    unique_ptr(const unique_ptr<T>& ptr) = delete;
    T& operator=(const unique_ptr<T>& ptr) = delete;

    // 移动构造 通过release来转移
    unique_ptr(unique_ptr<T>&& r_ptr) : _ptr(r_ptr.reslease()) {}
    unique_ptr<T>& operator=(unique_ptr<T>&& r_ptr)
    {
        reset(r_ptr.reslease());
        return *this;
    }

    // 控制生命周期 要delete
    void reset(T* ptr)
    {
        if (_ptr != nullptr)
        {
            delete _ptr;
        }
        _ptr = ptr;        
    }

    // 释放了内存的所有权 也就不控制生命周期 不要delete
    T* reslease()
    {
        T* tmp = _ptr;
        _ptr = nullptr;
        return tmp;
    }

    void swap(unique_ptr<T>& other)
    {
        using std::swap;
        swap(_ptr,other._ptr);
    }

    T* get() { return _ptr; }
    T& operator*() { return *_ptr; }
    T* operator->() { return _ptr; }

private:
    T* _ptr;
};