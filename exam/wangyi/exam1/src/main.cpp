#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int gui_num;
    cin>>gui_num;
    vector<vector<int>> gui(gui_num);
    getchar();
    for (size_t i = 0; i < gui_num; i++)
    {        
        string str;
        getline(cin,str);
        istringstream out(str);

        vector<int> g;
        string st;
        while (out >> st)
            g.push_back(stoi(st.c_str()));
        gui.push_back(g);
    }
    // cout<<"guinum:"<<gui_num<<" gui.szie:"<<gui.size()<<endl;
    // for (size_t i = 0; i < gui.size(); i++)
    // {
    //     cout<<"gui["<<i<<"].size:"<<gui[i].size()<<endl;        
    // }

    int time_num;
    cin>>time_num;
    vector<int> times;
    int time;
    for (size_t i = 0; i < time_num; i++)
    {
        cin>>time;
        times.push_back(time);
    }
    int max_dist = 0;
    for (size_t t = 0; t < times.size(); t++)// 对于每一种比赛时间长度
    {
        // 求t秒的时间谁跑的距离更长
        for (size_t i = gui_num; i < gui.size(); i++)// 遍历乌龟
        {   
            int dist = 0;
            if (gui[i].size() <= 3)// 只有一个阶段
            {
                dist += times[t] * gui[i][2];
            }
            else// 多个阶段
            {
                // 确定比赛是假可以到达第几阶段
                int level;// 时刻的序号
                for (level = 1; level < gui[i].size();)// 遍历一只龟
                    if (times[t] > gui[i][level])
                        level += 2;
                for (size_t j = 1; j < gui[i].size()-2; j++)// 遍历一只龟
                {
                    if (j < level)// 这一阶段跑满
                    {
                        dist += gui[i][j+1] * (gui[i][j+2] - gui[i][j]);
                    }
                    else// j==level
                    {
                        dist += gui[i][j+1] * (times[t] - gui[i][j]);
                        break;
                    }                    
                }
            }
            
            if (dist > max_dist)
                max_dist = dist;            
        }
        cout<<max_dist;
    }
}