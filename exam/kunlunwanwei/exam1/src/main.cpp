#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> v;
    int n = 5;
    while (n--)
    {
        string aaa;
        getline(cin,aaa);    
        v.push_back(aaa);
    }
    for (auto s : v)
    {
        printf("%s\n",s.c_str());
    }
    
}