// #面试题63 股票的最大利润
// 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
// 要求时间复杂度为O(n)。

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit2(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        vector<int> dp; // dp[i]:截止第i天，历史最低价
        dp.push_back(prices[0]);
        int max = 0;
        for (size_t i = 1; i < prices.size(); i++)
        {
            dp.push_back(prices[i] < dp[i - 1] ? prices[i] : dp[i - 1]);
            if (max < prices[i] - dp[i]) // 今天价格-历史最低价
                max = prices[i] - dp[i];
        }
        return max;
    }

    int maxProfit2(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        vector<int> dp; // dp[i]:前i日的最大利润 包括prices[i]
        // d[i] = max(d[i-1],d[i]-min(prices[0:i]))
        dp.push_back(0); // 第一天利润为0
        int minPrice = prices[0];
        for (size_t i = 1; i < prices.size(); i++)
        {
            minPrice = minPrice < prices[i] ? minPrice : prices[i];
            dp.push_back((prices[i] - minPrice) > dp[i - 1] ? (prices[i] - minPrice) : dp[i - 1]);
        }
        return dp[dp.size() - 1];
    }

    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int lowerst = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            max_profit = max(max_profit, prices[i] - lowerst);
            lowerst = min(lowerst, prices[i]);
        }
        return max_profit;
    }
};

int main()
{
    Solution s;
    vector<int> list = {7, 1, 5, 3, 6, 4};
    // vector<int> list = {7,6,4,3,1};
    printf("%d", s.maxProfit(list));
}