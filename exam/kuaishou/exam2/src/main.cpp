#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    
};

int main()
{
    int n = 0;
    cin>>n;

    vector<string> st;
    for (size_t i = 0; i < n; i++)
    {
        string str = "";
        cin>>str;
        st.push_back(str);
    }
    for (auto str : st)// 每一个输入
    {
        map<char,int> char_map;
        for (char word : str)
        {
            if (char_map.find(word) != char_map.end())// 说明这个字符出现过
            {
                char_map[word] += 1;// 数量加一
            }
            else
            {
                char_map.insert(pair<char,int>(word,1));
            }            
        }
        int jishu = 0;//统计出现奇数次的字符个数
        for (map<char,int>::iterator iter = char_map.begin(); iter != char_map.end(); iter++)
        {
            if (iter->second % 2 == 1)// 奇数
            {
                jishu++;
            }
        }
        // printf("%s %d ",str.c_str(),jishu);
        if (jishu % 2 == 1)//奇数的个数是奇数
        {
            cout<<"Cassidy"<<endl;
        }
        else
        {
            cout<<"Eleanore"<<endl;
        }
    }
}