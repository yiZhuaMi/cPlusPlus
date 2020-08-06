#include <iostream>
using namespace std;

template <typename T>
class SharedPtr
{
public:
    SharedPtr(T* p) : _ptr(p), _ref_count(1) {}
    SharedPtr(SharedPt<T>r& other)
    {
        _ptr = other._ptr;
        _ref_count = other._ref_count;
        ++*_ref_count;
    }

    ~SharedPtr()
    {
        if (_ptr != nullptr && --*_ref_count <= 0)
        {
            delete _ptr;
            delete _ref_count;
        }
    }

    SharedPtr& operator=(SharedPtr& other)
    {
        if (other != this)
        {
            ++*other._ref_count;
            --*_ref_count;
            if (_ref_count <= 0 && _ptr != nullptr)
            {
                delete _ptr;
                delete _ref_count;
            }
            _ptr = other._ptr;
            _ref_count = other._ref_count;
        }
        return *this;
    }

    T* get() { return _ptr; }
    T& operator* { return *_ptr; }
    T* operator-> { return _ptr; }

private:
    T* _ptr;
    int* _ref_count;
};