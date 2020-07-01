// #763. 划分字母区间
// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只
// 会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
// 示例 1：
// 输入：S = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]
// 解释：
// 划分结果为 "ababcbaca", "defegde", "hijhklij"。
// 每个字母最多出现在一个片段中。
// 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int start = 0, end = 0;
        // 用来记录字符char在s中的最大下标
        unordered_map<char,int> m;
        // 利用map不可重复，遍历一趟得到每个字母的最大下标
        for (int i = 0; i < S.size(); i++)
            m[S[i]] = i;

        for (int i = 0; i < S.size(); i++)
        {
            // 区间中有更长的，就扩大end
            end = max(end,m[S[i]]);
            // 如果i追上了end 就添加
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.partitionLabels("ababcbacadefegdehijhklij");
}