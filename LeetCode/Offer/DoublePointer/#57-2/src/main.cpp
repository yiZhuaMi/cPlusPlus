//#面试题57-2 和为s的连续正数序列

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence2(int target) {
        if (target == 1 || target == 2)
            return {};
        vector<vector<int>> v;
        for (size_t i = 1; i < target / 2; i++)// 起始 正整数从1开始
        {
            for (size_t j = 2; j < target; j++)// 长度 至少含有两个数
            {
                if ((2 * i + j - 1) * j / 2 == target)
                {
                    vector<int> ve;
                    for (size_t k = 0; k < j; k++)
                    {
                        ve.push_back(i+k);
                    }
                    v.push_back(ve);
                }
            }            
        }
        return v;
    }
    // 双指针
    // 用l,r表示区间
    vector<vector<int>> findContinuousSequence(int target) {
        int sum = 0;
        vector<vector<int>> ve;
        vector<int> v;
        for (size_t l = 1, r = 2; l < target/2+1;)
        {
            // 复习：连续序列，用公式求和
            sum = (l + r) * (r - l + 1) / 2;
            if (sum > target)// 以l为起点没有解，窗口缩小
                l++;
            else if (sum < target)// r右移，窗口增大
                r++;
            else// bingo
            {
                v.clear();
                for (size_t i = 0; i < r-l+1; i++)
                    v.push_back(l+i);
                ve.push_back(v);
                l++;
            }
        }
        return ve;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = s.findContinuousSequence(9);
    printf("[");
    for (size_t i = 0; i < v.size(); i++)
    {
        printf("[");
        for (size_t j = 0; j < v[0].size(); j++)
        {
            printf("%d ",v[i][j]);
        }
        printf("]");
    }
    printf("]");
}