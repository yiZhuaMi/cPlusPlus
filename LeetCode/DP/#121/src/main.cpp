//#121 买卖股票的最佳时机
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
// 注意：你不能在买入股票前卖出股票。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 时间复杂度O(n) 空间复杂度O(n)
    int maxProfit2(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int lowerst = prices[0];
        vector<int> dp(prices.size(),0);// dp[i]:当天或之前卖出股票能赚的最多的钱
        dp[0] = 0;
        for (size_t i = 1; i < prices.size(); i++)
        {
            dp[i] = max(dp[i-1],prices[i]-lowerst);
            if (prices[i] < lowerst)
                lowerst = prices[i];
        }
        return dp[prices.size()-1];
    }

    // 时间复杂度O(n) 空间复杂度O(1)
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int lowerst = prices[0], max_porfit = 0;
        for (size_t i = 1; i < prices.size(); i++)
        {
            max_porfit = max(prices[i]-lowerst,max_porfit);
            if (prices[i] < lowerst)
                lowerst = prices[i];
        }
        return max_porfit;
    }
};

int main()
{
    vector<int> v = {7,6,4,8,1};
    Solution s;
    printf("%d\n",s.maxProfit(v));
}