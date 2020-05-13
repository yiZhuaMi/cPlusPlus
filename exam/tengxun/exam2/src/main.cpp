#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;


int main()
{
    int batch;
    cin>>batch;
    vector<vector<vector<int>>> set;
    for (size_t i = 0; i < batch; i++)
    {
        int n;
        cin>>n;
        vector<vector<int>> row(2*n,vector<int>(2,-1));
        for (size_t j = 0; j < 2*n; j++)
        {
            cin>>row[j][0]>>row[j][1];
        }
        set.push_back(row);
    }
    for (size_t i = 0; i < set.size(); i++)// 一组数据
    {
        double min = INT32_MAX;
        for (size_t j = 0; j < set[i].size()/2; j++)// 前一半
        {
            for (size_t k = set[i].size()/2; k < set[i].size(); k++)// 后一半
            {
                double dist = sqrt(pow(set[i][j][0]-set[i][k][0],2) + pow(set[i][j][1]-set[i][k][1],2));
                if (dist < min)
                {
                    min = dist;
                }

            }
            
        }
        printf("%.3f\n",min);
    }
    
}