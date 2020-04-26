#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    
};

int main()
{
    int s_num, c_num;
    cin>>s_num>>c_num;

    
    vector<vector<int>> table;
    
    for (size_t i = 0; i < s_num; i++)
    {
        vector<int> student(c_num);
        for (size_t j = 0; j < c_num; j++)
        {
            cin>>student[j];
        }
        table.push_back(student);
    }
    
    // vector<int> best_s_ind(c_num);// 单科高分的人的ind
    set<int> s;// 单科高分的人的ind 同科目可能有多个
    // 一个人只能那一次奖 同一科目可颁给多个人
    for (size_t i = 0; i < c_num; i++)// 科目
    {
        int max_ind = 0;// 该科最高分的ind 假设最高分是第一个人
        for (size_t j = 0; j < s_num; j++)// 人
        {
            if (table[j][i] > table[max_ind][i])
                max_ind = j;
        }
        for (size_t j = 0; j < s_num; j++)
        {
            if (table[j][i] == table[max_ind][i])// 这一科目有几个人获得了这个最高分
            {
                s.insert(j);
            }
            
        }        
    }
    cout<<s.size();
   
}