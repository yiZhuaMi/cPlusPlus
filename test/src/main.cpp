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
    ~Myclass();
};

Myclass::Myclass() : data(0) {}

int main()
{
    Myclass a;

    vector<int> v = {0,1,2,3};
    auto ite = find(v.begin(),v.end(),2);
    
    return 0;
}