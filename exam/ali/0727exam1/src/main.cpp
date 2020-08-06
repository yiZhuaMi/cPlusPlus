#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int T, n, a;
    cin>>T;
    while (T--)
    {
        cin>>n;
        set<int> se;
        while (n--)
        {
            cin>>a;
            se.insert(a);
        }
        if (se.size() % 2 == 1)
        {
            cout<<"NIUNIU"<<endl;
        }
        else
        {
            cout<<"NIUMEI"<<endl;
        }
    }
}