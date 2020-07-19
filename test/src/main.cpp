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


int main()
{
    int a_size = sizeof(A);
    Myclass a;

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