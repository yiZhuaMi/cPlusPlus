#include <iostream>
using namespace std;

template <typename T>
class My_Shared_Ptr
{
public:
    My_Shared_Ptr(T* p) : _ptr(p), _ref_count(1) {printf("construct sptr at %d\n",*p);}
    My_Shared_Ptr(My_Shared_Ptr<T>& other) : _ptr(other._ptr), _ref_count(&(++*other._ref_count)) 
    {printf("copy construct sptr at %d\n",*other._ptr);}

    ~My_Shared_Ptr() 
    {
        if (_ptr != nullptr && --*_ref_count <= 0)
        {
            delete _ptr;
            delete _ref_count;
            printf("deconstruct sptr at %d\n",*_ptr);
        }
    }

    My_Shared_Ptr<T>& operator=(My_Shared_Ptr<T>& other)
    {
        ++*other._ref_count;
        --*_ref_count;
        if (*_ref_count <= 0 && _ptr != nullptr)
        {
            delete _ptr;
            delete _ref_count;
            printf("operator= delete %d\n",*_ptr);
        }
        _ptr = other._ptr;
        // 引用计数指针 指向同一个 int变量 共享计数!
        _ref_count = other._ref_count;
        return *this;
    }

    T& operator*() { return *_ptr; }
    T* operator->() { return _ptr; }

    T* get() { return _ptr; }


private:
    T* _ptr;
    // 实现共享引用计数的精髓
    int *_ref_count;     //should be int*, rather than int
};

int main()
{
    int a;
    My_Shared_Ptr<int> p1(new int(666));
    My_Shared_Ptr<int> p2(p1);
    My_Shared_Ptr<int> p3(new int(999));
    p3 = p2;
}