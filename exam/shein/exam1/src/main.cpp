#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

// 100%
int main()
{
    // string str = "aaddd ccddac";
    string str;
    while (cin>>str)
    {
        map<char,int> m;
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || 
                (str[i] >= 'A' && str[i] <= 'Z') || 
                (str[i] >= '0' && str[i] <= '9') ||
                str[i] == ' ')
            {
                m[str[i]]++;
            }
        }
        map<int,vector<char>> data;// <出现次数，字符>
        for (auto ite = m.begin(); ite != m.end(); ite++)
        {
            // printf("字母 出现次数 <%c,%d>\n",ite->first,ite->second);   
            data[ite->second].push_back(ite->first);
        }
        for (auto ite = data.rbegin(); ite != data.rend(); ite++)
        {
            // printf("出现次数 %d 的有 %d 个字母\n",ite->first,ite->second.size());   
            for (int i = 0; i < ite->second.size(); i++)
            {
                printf("%c",ite->second[i]);   
            }        
        }
        m.clear();
        data.clear();
    }
    return 0;
}