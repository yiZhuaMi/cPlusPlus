// #面试题48. 最长不含重复字符的子字符串
// 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 滑动窗口
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, max_len = 0;
        set<int> char_set;
        for (int i = 0; i < s.length(); i++)
        {
            if (char_set.find(s[i]) != char_set.end())// 有重复的 就从当前串最左一直删,包括重复的
            {
                while (s[left] != s[i])// 删重复之前的
                {
                    char_set.erase(s[left]);// 从子串中删除一个
                    left++;// 子串左边界右移
                }
                // 删除重复的
                char_set.erase(s[left]);// 从子串中删除一个
                left++;// 子串左边界右移
            }
            // 必须先删重复的再添加，否则一添加就被删除
            char_set.insert(s[i]);// 子串添加一个
            right++;// 子串右边界右移

            max_len = max(max_len,right-left);
        }
        return max_len;
    }
};

int main()
{
    Solution s;
    printf("%d",s.lengthOfLongestSubstring("pwwkew"));
}