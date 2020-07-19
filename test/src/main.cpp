#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Myclass
{
private:
    int data;
public:
    Myclass() : data(0) {}
};

void print_v(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ",v[i]);
    }
    cout<<endl;
}

struct A
{
    // char a1;
    // char a2;
    // char a3;
    uint8_t a1;
    uint16_t a2;
    uint32_t a3;
};

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
    int a_size = sizeof(A);
    
    int *nn = new int(666);
    My_Shared_Ptr<int> p1(nn);
    // My_Shared_Ptr<int> p2(p1);
    // My_Shared_Ptr<int> p3(new int(999));
    // p3 = p2;

    vector<int> v = {0,1,2,3};
    print_v(v);
    auto ite = v.begin() + 1;
    int k = 2;
    while (k--)
    {
        v.erase(ite);
    }
    print_v(v);

    ite = v.begin() + 1;
    for (int i = 1; i <= 2; i++)
    {
        v.insert(ite,i);
        ite += 2;
    }
    print_v(v);
    
    
    return 0;
}