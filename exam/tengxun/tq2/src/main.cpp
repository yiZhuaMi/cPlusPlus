/*#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

vector<string> res;
set<string> se;
int cap;

void dfs(string& str, string& line, int i)
{
    if (res.size() > cap)
        return;
    if (se.find(line) == se.end())
    {
        res.push_back(line);
        se.insert(line);
    }

    for (; i < str.length(); i++)
    {
        line.push_back(str[i]);
        dfs(str,line,i+1);
        line.pop_back();
    }
}

vector<string> sub_str(string& str) {
    string line;
    dfs(str,line,0);
    return res;
}

int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    cap = k;
    
    if (str.length() == 0)
        cout<<"";
    else if (str.length() == 1)
        cout<<str[0];
    else
    {
        sort(str.begin(),str.end());
        sub_str(str);
        cout<<res.back();    
    }
}*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

set<string> se;

void dfs(string& str, string line, int i, vector<string>& res, const int cap)
{
    if (res.size() > cap)
        return;
    if (se.find(line) == se.end())
    {
        res.push_back(line);
        se.insert(line);
    }

    for (; i < str.length(); i++)
    {
        line.push_back(str[i]);
        dfs(str,line,i+1,res,cap);
        line.pop_back();
    }
}

vector<string> sub_str(string& str, vector<string>& res, const int cap) {
    string line;
    dfs(str,line,0,res,cap);
    return res;
}

int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    int cap = k;

    vector<string> res;


    if (str.length() == 0)
        cout<<"";
    else if (str.length() == 1)
        cout<<str[0];
    else
    {
        sort(str.begin(),str.end());
        sub_str(str,res,cap);
        cout<<res.back();    
    }
}