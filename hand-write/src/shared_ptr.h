#include <iostream>
using namespace std;

// 实现shared_ptr
template <typename T>
class My_Shared_Ptr
{
public:
    My_Shared_Ptr(T* p) : _ptr(p), _ref_count(1) { printf("construct sptr at %d\n",*p); }

    ~My_Shared_Ptr() 
    {
        if (_ptr != nullptr && --*_ref_count <= 0)
        {
            delete _ptr;
            delete _ref_count;
            printf("deconstruct sptr at %d\n",*_ptr);
        }
    }

    // 参数非const
    My_Shared_Ptr(My_Shared_Ptr<T>& other) : _ptr(other._ptr), _ref_count(other._ref_count)) 
    {
        ++*_ref_count;
        printf("copy construct sptr at %d\n",*other._ptr);
    }
    
    // 参数非const
    My_Shared_Ptr<T>& operator=(My_Shared_Ptr<T>& other)
    {
        // 修改计数
        ++*other._ref_count;
        --*_ref_count;
        // 是否销毁
        if (*_ref_count <= 0 && _ptr != nullptr)
        {
            delete _ptr;
            delete _ref_count;
            printf("operator= delete %d\n",*_ptr);
        }
        // 赋值
        _ptr = other._ptr;
        _ref_count = other._ref_count;// 引用计数指针 指向同一个 int变量 共享计数!
        return *this;
    }

    void swap(My_Shared_Ptr<T>& other)
    {
        using std::swap;
        swap(_ptr,other._ptr);
        swap(_ref_count,other._ref_count);
    }

    T* get() { return _ptr; }
    T& operator*() { return *_ptr; }
    T* operator->() { return _ptr; }


private:
    T* _ptr;
    // 实现共享引用计数的精髓
    int *_ref_count;     //should be int*, rather than int
};