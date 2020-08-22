//#面试题45 把数组排成最小的数
// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        string res;
        vector<string> n_str;
        // 所有的数字都转字符串
        for (auto n : nums)
            n_str.push_back(to_string(n));
        // 复习：lambda表达式 '<'升序->小的在前->先被添加到res->在res的左边（高位）
        sort(n_str.begin(),n_str.end(),[] (const string& a, const string& b) -> bool {return a + b < b + a;});
        for (auto c : n_str)
            res += c;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> list = {3,30,34,5,9};
    printf("\n%s",s.minNumber(list).c_str());
}