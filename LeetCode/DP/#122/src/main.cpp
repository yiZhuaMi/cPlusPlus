// #122 买卖股票的最佳时机 II
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int total_profit = 0;
        for (size_t i = 0; i < prices.size()-1; i++)
            if (prices[i] < prices[i+1])
                total_profit += prices[i+1] - prices[i];        
        return total_profit;
    }
};

int main()
{
    vector<int> v = {7,1,5,3,6,4};
    Solution s;
    printf("%d\n",s.maxProfit(v));
}