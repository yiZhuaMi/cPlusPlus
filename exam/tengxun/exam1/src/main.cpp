#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int batch, action;
    cin>>batch;
    vector<vector<string>> v(batch);
    for (size_t i = 0; i < batch; i++)
    {
        cin>>action;
        getchar();
        for (size_t j = 0; j < action; j++)
        {
            string str;
            getline(cin,str);
            v[i].push_back(str);
        }
    }
    for (size_t i = 0; i < batch; i++)
    {
        queue<int> q;
        for (size_t j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].length() > 5)
            {
                q.push(stoi(v[i][j].substr(5,v[i][j].length())));
            }
            else if (v[i][j] == "TOP")
            {
                if (q.size() > 0)
                {
                    cout<<q.front()<<endl;
                }
                else
                {
                    cout<<-1<<endl;
                } 
            }
            else if (v[i][j] == "POP")
            {
                if (q.size() > 0)
                {
                    q.pop();
                }
                else
                {
                    cout<<-1<<endl;
                }                
            }
            else if (v[i][j] == "SIZE")
            {
                cout<<q.size()<<endl;
            }
            else if (v[i][j] == "CLEAR")
            {
                while (!q.empty())
                {
                    q.pop();
                }
            }
        }   
    } 
}