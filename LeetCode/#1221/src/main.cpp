// 1221. 分割平衡字符串
// 在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。
// 给出一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。
// 返回可以通过分割得到的平衡字符串的最大数量。
// 贪心算法

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s) {
        int res = 0, r_num = 0, l_num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                l_num++;
            if (s[i] == 'R')
                r_num++;
            if (l_num == r_num)
                res++;
        }
        return res;
    }
    
int main()
{
    Solution s;
}