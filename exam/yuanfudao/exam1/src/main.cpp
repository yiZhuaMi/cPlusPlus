#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin>>N;
    M = N;
    vector<vector<int>> v;
    set<int> se;
    while (M--)
    {
        vector<int> line(2);
        cin>>line[0]>>line[1];
        v.push_back(line);
        se.insert(line[0]);
        se.insert(line[1]);
    }
    sort(v.begin(),v.end());
    int count = N * 2;
    vector<char> vc;
    while (count > 0)
    {
        for (auto ite = se.begin(); ite != se.end(); ite++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (v[i][j] == *ite)
                    {
                        vc.push_back(j == 0 ? '(' : ')');
                        count--;
                    }
                }   
            }
        }
    }
    int n = 0, res = 0;
    for (auto c : vc)
    {
        if (c == '(')
            n++;
        else
            n--;
        res = max(res,n);
    }
    cout<<res;
}