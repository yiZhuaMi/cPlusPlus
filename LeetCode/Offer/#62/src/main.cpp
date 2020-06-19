// #面试题62. 圆圈中最后剩下的数字
// 0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除
// 第m个数字。求出这个圆圈里剩下的最后一个数字。
// 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个
// 数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 超时
    int lastRemaining(int n, int m) {
        vector<int> v(n,0);// 只用来记录是否被删除，不需要存值，因为值就等于ind
        int size = n;
        int ind = 0;// 指向v中数字的序号,其值就等于数字
        int boom = 0;// boom == m 则被删除
        while (size >= 1)
        {
            if (v[ind] != -1)// 还存在 没有被删除
            {
                if (size == 1)// 找到了最后剩下的
                    break;
                boom++;
                if (boom == m)
                {
                    v[ind] = -1;
                    boom = 0;
                    size--;
                }
            }
            // 控制ind
            ind++;
            // 到末尾 循环
            if (ind == n)
                ind = 0;
        }
        return ind;
    }   
};

int main()
{
    Solution s;
    printf("%d\n", s.lastRemaining(70866,116922));
}