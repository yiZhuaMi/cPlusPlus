//#乘法表（百度2016实习生真题）
							
// 题目描述								
// 度度熊和爷爷在玩一个乘法表游戏。乘法表的第i行第j列位置的元素为i*j，
// 并且乘法表下标编号从1开始，比如2 × 3乘法表为
// 1 2 3
// 2 4 6
// 爷爷十分聪明，对于n*m的乘法表，只要度度熊给出一个数k，爷爷就能立刻告
// 诉度度熊乘法表中元素按照不减顺序排列之后，第k个元素是多少。你能重复这个游戏吗？


#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int getInd(int n, int m, int k) {
        
        int ind = 1,dup = 0;
        map<int,int> sort_list;
        for (size_t i = 1; i <= n; i++)
            for (size_t j = 1; j <= m; j++)
                if (sort_list.find(i*j) == sort_list.end())
                    sort_list.insert(map<int,int>::value_type(i*j,ind++));//(value,key)
                else if (i*j < k)
                    dup++;
        
        for(std::map<int,int>::iterator it = sort_list.begin();it!=sort_list.end();it++) 
            cout<<"v:"<<it->first<<" k:"<<it->second<<endl;
       
        map<int,int>::iterator iter = sort_list.find(k-dup);
        if (iter != sort_list.end())
        {
            // cout<<"要找第几个:"<<k<<" 值:"<<iter->second<<endl;
            return iter->second;
        }
        else
            return -1;        
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.getInd(2,3,5));
}