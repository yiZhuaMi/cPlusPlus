//#面试题17 打印从1到最大的n位数

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> a;
        int num = 10;
        while (--n > 0) 
            num *= 10;
        for (size_t i = 1; i < num; i++)
        {
            a.push_back(i);
        }
        return a;
    }
};

int main()
{   
    Solution s;
    vector<int> v = s.printNumbers(1);

    printf("[%d,",v[0]);
    for (size_t i = 1; i < v.size()-1; i++)
    {
        printf("%d,",v[i]);
    }
    printf("%d]\n",v[v.size()-1]);
}