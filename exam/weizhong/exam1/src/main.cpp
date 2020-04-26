#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    
};

int main()
{
    int num = 0;
    cin>>num;

    map<int,int> card_set;
    for (size_t i = 0; i < num; i++)
    {
        int cash, extra;
        cin>>cash>>extra;
        card_set.insert(pair<int,int>(cash,extra));
    }
    int chouka = 1;
    int total = 0;
    // 金额从大到小
    cout<<"---------------------"<<endl;
    for (map<int,int>::reverse_iterator iter = card_set.rbegin(); iter != card_set.rend(); iter++)
    {
        printf("%d %d chouka=%d\n",iter->first,iter->second,chouka);
        if (chouka > 0)
        {
            printf("chouka = %d > 0\n",chouka);
            if (iter->second > 0)
            {
                printf("extra = %d\n",iter->second);
                chouka += iter->second - 1;
                total += iter->first;
            }
        }        
    }
    if (chouka > 0)// 剩下的都是次数不增加的了
    {
        // 金额从大到小
        for (map<int,int>::reverse_iterator iter = card_set.rbegin(); iter != card_set.rend(); iter++)
        {
            if (iter->second <= 0)// 次数不增加的
            {
                chouka--;
                total += iter->first;
            }
        }
    }
    cout<<total<<endl;
}