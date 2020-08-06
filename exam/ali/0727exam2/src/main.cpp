#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> num(n);
    priority_queue<int,vector<int>,greater<int>> q_picked;
    /*
    while (n--)
    {
        int len;
        cin>>len;
        vector<int> line(len);
        int a;
        while (len--)
        {
            cin>>a;
            line.push_back(a);
        }
        num.push_back(line);
    }
    */
    while (n--)
    {
        int len;
        cin>>len;
        int ind = 1, a;
        while (ind <= len)
        {
            cin>>a;
            if (ind == 1 || ind == len)
            {
                q_picked.push(a);
                if (q_picked.size() > m)
                    q_picked.pop();
            }  
            ind++;
        }
    }
    int res = 0;
        printf("size:%d\n",q_picked.size());
    while (!q_picked.empty())
    {
        printf("sdasd:%d\n",q_picked.top());
        res += q_picked.top();
        q_picked.pop();
    }
    cout<<res;
}