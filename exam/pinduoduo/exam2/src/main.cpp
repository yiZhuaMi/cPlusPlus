#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
    int batch;
    cin>>batch;
    vector<vector<int>> q;
    for (size_t i = 0; i < batch; i++)
    {
        int bian_num;
        cin>>bian_num;
        vector<int> v(bian_num);
        for (size_t j = 0; j < bian_num; j++)
        {
            cin>>v[j];
        }
        q.push_back(v);
    }
    for (size_t i = 0; i < batch; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < q[i].size(); j++)
        {
            sum += q[i][j];
        }
        // printf("sum:%d ",sum);
        if (sum % 4 == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}