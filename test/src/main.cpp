#include <iostream>
#include <vector>
#include <algorithm>
#include "thread_pool.h"
#include "unistd.h"
using namespace std;

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

void func1(int t_id)
{
    printf("%d start\n",t_id);
    sleep(1);
    printf("%d end\n",t_id);
}



int main()
{
    ThreadPool t_pool(4);
    function<void(int)> f = func1;
    for (size_t i = 0; i < 4; i++)
    {
        t_pool.excute(f);
    }
    getchar();
}