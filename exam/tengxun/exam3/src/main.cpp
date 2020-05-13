#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string> v;
    getchar();
    for (size_t i = 0; i < n; i++)
    {
        string str;
        getline(cin,str);
        v.push_back(str);
    }
    stack<int> s1, s2;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i].size() > 4)// add
        {
            s1.push(stoi(v[i].substr(4,v[i].length())));
        }
        else if (v[i] == "peek")
        {
            if (s1.empty() && s2.empty())
            {
                return -1;
            }
            if (s2.empty())// s1非空
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            cout<<s2.top()<<endl;
        }
        else if (v[i] == "poll")
        {
            if (s1.empty() && s2.empty())
            {
                return -1;
            }
            if (s2.empty())// s1非空
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            s2.pop();// delete
        }
    } 
}