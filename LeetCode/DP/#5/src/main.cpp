//#5 最长回文子串
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
// #516 最长回文子序列 的做法
// 1.涉及两个字符串/数组时（比如最长公共子序列），dp 数组的含义如下：
// 在子数组 arr1[0..i] 和子数组 arr2[0..j] 中，我们要求的子序列（最长公共子序列）长度为 dp[i][j]。
// 2.只涉及一个字符串/数组时（比如本文要讲的最长回文子序列），dp 数组的含义如下：
// 在子数组 array[i..j] 中，我们要求的子序列（最长回文子序列）的长度为 dp[i][j]。

// 中心扩展算法
// 回文可以从它的中心展开，并且只有 2n - 1 个这样的中心。
// 因为回文的中心要区分单双。
// 假如回文的中心为 双数，例如 abba，那么可以划分为 ab bb ba，对于n长度的字符串，这样的划分有 n-1 种。
// 假为回文的中心为 单数，例如 abcd, 那么可以划分为 a b c d， 对于n长度的字符串，这样的划分有 n 种。

    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int start = 0, end = 0, max_len = 0;// 记录最后的最长回文子串
        for (size_t i = 0; i < s.length(); i++)
        {
            int len1 = expandAroundCenter(s,i,i);
            int len2 = expandAroundCenter(s,i,i+1);
            int len = max(len1,len2);
            if (len > end - start)// 更长
			{
				start = i - (len - 1) / 2;// ！！！！！！！！！！！！！！！！！
				end = i + len / 2;
			}
        }
        return s.substr(start,end - start + 1);// (开始，长度)!!!!!!!!!!!!!
    }
    
    // 找出以left right为中心的最长回文子串长度
    int expandAroundCenter(string s, int left, int right)
    {
        while (left >= 0 && right <= s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;// i,i+1会返0
    }
};

int main()
{
    Solution s;
    printf("%s\n",s.longestPalindrome("babad").c_str());
}