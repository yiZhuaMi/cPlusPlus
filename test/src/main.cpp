#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    Solution() = default;
    Solution(int x):data(x){}
    
    Solution func(int x)
    {
        return Solution(x);
    }
    int getData()
    {
        return data;
    }
    int& get()
    {
        return data;
    }

private:
    int data;
};

# pragma pack(4)
struct num_data
{
    // int i1;
    char c1;
    double d1;
};

class Animal
{
public:
    Animal():id("Animal"){};
    Animal(int w):id("Animal"),weight(w){}
    ~Animal() = default;
    virtual void eat()
    {
        printf("Animal::eat()\n");
    }
private:
    int weight;
    string id;
};

class Tiger : public Animal
{
public:
    Tiger():id("Tiger"){};
    Tiger(int w):id("Tiger"),weight(w){};
    ~Tiger() = default;
    void eat()
    {
        printf("Tiger::eat()\n");
    }
private:
    int weight;
    string id;
};

int main()
{
    vector<int> v = {0,1,2,3,4,5};
    for (auto ite = v.begin(); ite != v.end()-1;)
    {
        printf("ite.val:%d\n",*ite);
        v.erase(ite);
    }
    // v.erase(v.begin()+2,v.begin()+5);
    for (auto c : v)
    {
        printf("%d ",c);
    }


    // Animal* ani = new Animal(10);
    // Animal* ani2 = new Tiger(20);
    // ani->eat();
    // ani2->eat();

    // int a = 42;
    // // const int a = 42;
    // const int* ptr = &a;
    // int* ptr2 = const_cast<int*>(ptr);
    // *ptr2 = 4;
    // int c = 1;

    // Solution* s = new Solution(1);
    // Solution s1;
    // printf("%d\n",s->get());
    // s->get() += 1;
    // printf("%d\n",s->get());    
    
    // printf("%lu\n",sizeof(Solution));
    // printf("%lu\n",sizeof(s));// 8 64位一个指针大小
    // printf("%lu\n",sizeof(s1));

    // printf("%lu\n",sizeof(num_data));

}