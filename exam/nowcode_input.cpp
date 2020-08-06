#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
 
int main()
{
    // 1 2 3
    // 4 5
    // 0 0 0 0 0
    int n, a, sum = 0;
    while (cin>>n)
    {
        sum += n;
        if (cin.get() == '\n')
        {
            cout<<sum<<endl;
            sum = 0;
        }
    }

    // 4 1 2 3 4
    // 5 1 2 3 4 5
    int n, a, sum = 0;
    while (cin>>n)
    {
        while (n--)
        {
            cin>>a;
            sum += a;
        }
        cout<<sum<<endl;
        sum = 0;
    }

    // a c bb
    // f dddd
    // nowcoder
    string str;
    vector<string> v;
    while (cin>>str)
    {
        v.push_back(str);
        if (cin.get() == '\n')
        {
            sort(v.begin(),v.end());
            for (int i = 0; i < v.size(); i++)
            {
                if (i == v.size()-1)
                    cout<<v[i]<<endl;
                else
                    cout<<v[i]<<" ";
            }
            v.clear();
        }
    }

    // a,c,bb
    // f,dddd
    // nowcoder
    vector<string> v;
    string line, str;
    while (cin>>line)
    {
        stringstream ss(line);
        while (getline(ss,str,','))
        {
            v.push_back(str);
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (i == v.size()-1)
                cout<<v[i]<<endl;
            else
                cout<<v[i]<<",";
        }
        v.clear();

    }
}