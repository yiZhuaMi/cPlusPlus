#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

class testDemo
{
public:
    testDemo(int num):num(num){
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    }
private:
    int num;
};

int main()
{
    const int a = 10;
    // int* p = &a;
    int* p = (int*)&a;
    *p = 20;
    cout<<a<<" "<<*p<<endl;

    const volatile int b = 10;
    int* pb = (int*)&b;
    *pb = 20;
    cout<<b<<" "<<*pb<<endl;

    char* s1 = "asd";
    char s2[] = "asd";
    string s3 = "asd";
    // s1[1] = 'b';
    s2[1] = 'b';
    s3[1] = 'b';
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<&s1<<endl;
    cout<<&s2<<endl;
    cout<<&"s3"<<endl;


    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);  
    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2);
    demo1.reserve(1);

    int stack = 1;
    int* heap = new int(1);
    string s4 = "sadasdassadadasdadasdasd";
    // cout<<sizeof(s4);
    cout<<&stack<<endl;
    cout<<heap<<endl;
    cout<<&s4<<endl;
}