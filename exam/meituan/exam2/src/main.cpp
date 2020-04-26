#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int a, b, m, x;
    cin>>a>>b>>m>>x;
    // int a = 2, b = 1, m = 5, x = 2;
    int count = 10;
    vector<int> v;
    while (count--)
    {
        x = (a * x + b) % m;
        v.push_back(x);
        // printf("%d v.size:%d\n",x,v.size());
    }

    // for (size_t i = 0; i < v.size(); i++)
    //     printf("%d ",v[i]);
    // cout<<endl;

    int len = 0;// 循环序列的长度
    bool found = false;

    for (size_t ind = 0; ind < v.size(); ind++)// 验证的数 从第一个开始
    {
        for (size_t i = 1; i < v.size(); i++)// 找第ind个数对应的len
        {
            // if (found)
            //     break;
            if (v[ind] == v[i])// 找到一个len 用第一个数验证
            {
                found = true;
                len = i;
                for (size_t ind = 0; ind < v.size(); ind++)// 验证的数 从第一个开始
                {
                    int mul = 1;// len的倍数
                    while (mul * len < v.size())
                    {
                        if (v[ind] != v[mul * len])
                        {
                            found = false;
                            break;
                        }
                        mul++;
                    }
                    if (!found)// len验证失败 找下一个len
                        break;
                }
                if (found)// 都验证成功
                {
                    cout<<len<<endl;
                    return;
                }
            }
            
        }

    }

    
    // cout<<len<<endl;
}