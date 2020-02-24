//#14.最长公共前缀

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0, num = 0;
        while(!strs.empty())//用count遍历字母
        {
            for (size_t i = 1; i < strs.size(); i++)//遍历单词
            {
                num += strs[0][count] - strs[i][count];
                if(num) break;
            }    
            if(num == 0 && count < strs[0].size())//全部完全相等->size相等 否则num!=0
                count++;
            else
                break;//有出现不相等的
        }
        return strs.empty() ? "" : strs[0].substr(0,count);
    }
};

int main()
{
    Solution s;
    vector<string> str = {"abc","a","abcb"};
    printf("%s\n",s.longestCommonPrefix(str).c_str());
}