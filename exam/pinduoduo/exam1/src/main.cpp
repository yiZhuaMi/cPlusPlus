#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_v(vector<size_t> v)
{
    for (auto c : v)
    {
        // printf("[%d]",c);
    }
    // printf("\n");
}

int main()
{
    size_t N, num = 0;
    // N = 5;
    cin>>N;
    vector<size_t> v(N);
    for (size_t i = 0; i < v.size(); i++)
    {
        cin>>v[i];
    }
    // v[0]=100;
    // v[1]=111;
    // v[2]=111;
    // v[3]=999;
    // v[4]=5;
    print_v(v);
    sort(v.begin(),v.end());
    print_v(v);
    for (size_t i = 1; i < v.size();)
    {
        // printf("i=%d\n",i);
        print_v(v);
        if (v[i] == v[i-1])
        {
            v[i]++;
            num++;
            sort(v.begin()+i,v.end());
            print_v(v);
        }
        else
        {
            i++;
        }
    }
    cout<<num<<endl;
}