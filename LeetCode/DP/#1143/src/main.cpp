//#1143 最长公共子序列
// 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
// 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的
// 相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两
// 个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
// 若这两个字符串没有公共子序列，则返回 0。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j]:text1[1~i]和text2[1~j]的最长公共子序列长度。
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for (size_t i = 1; i < text1.length()+1; i++)
        {
            for (size_t j = 1; j < text2.length()+1; j++)
            {
                if (text1[i-1] == text2[j-1])// 这个字符会出现在cls中
                {
                    dp[i][j] = dp[i-1][j-1] + 1;// text1取（1～i-1）且text2取（1～j-1）时的cls
                }
                else// 两个字符不相等，则其中一个不再cls中，取使cls最长的
                {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
};

int main()
{
    string str1 = "abcde";
    string str2 = "ace";
    Solution s;
    printf("%d\n",s.longestCommonSubsequence(str1,str2));
}