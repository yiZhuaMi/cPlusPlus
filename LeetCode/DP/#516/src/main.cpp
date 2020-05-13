//#516 最长回文子序列
// 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
// 1.涉及两个字符串/数组时（比如最长公共子序列），dp 数组的含义如下：
// 在子数组 arr1[0..i] 和子数组 arr2[0..j] 中，我们要求的子序列（最长公共子序列）长度为 dp[i][j]。
// 2.只涉及一个字符串/数组时（比如本文要讲的最长回文子序列），dp 数组的含义如下：
// 在子数组 array[i..j] 中，我们要求的子序列（最长回文子序列）的长度为 dp[i][j]。

// 所以有dp[i][j]:i～j中最长的回文子序列的长度。
// dp[i + 1][j - 1] : ij之间（不包括ij）的最长的回文子序列的长度。
    int longestPalindromeSubseq(string s) {
        if (s.length() == 1)
            return 1;        
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        for (size_t i = 0; i < s.length(); i++)
            dp[i][i] = 1;// 指针都指向同一个位置，回文长度是1。
        
        // 遍历右上三角
        for (int i = dp.size()-1; i >= 0; i--)// 为了保证(i,j)左、下、左下的dp都被计算出来，从倒数第二行往上
        {
            for (int j = i+1; j < dp[i].size(); j++)// 列 从左往右
            {
                if (s[i] == s[j])// 新回文对
                {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);// 分别加入 s[i+1..j-1] 中，看看哪个子串产生的回文子序列更长。
                }                
            }
            
        }
        return dp[0][s.length()-1];
    }
};

int main()
{
    string str = "bbbab";
    Solution s;
    printf("%d\n",s.longestPalindromeSubseq(str));
}