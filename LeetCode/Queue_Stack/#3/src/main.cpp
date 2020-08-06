//#3 无重复字符的最长子串
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串(必须连续) 的长度。

#include <iostream>
#include <string>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring2(string s) {
        if (s.empty())
            return 0;
        queue<char> q;// 用来维护以s[i]结尾的最长无重复子串
        set<char> char_set;// 用来判断是否与队列中元素重复
        q.push(s[0]);
        char_set.insert(s[0]);
        int max_len = 1;
        for (size_t i = 1; i < s.size(); i++)
        {
            if (char_set.find(s[i]) != char_set.end())// 重复
            {
                // 把s[i]在queue中相同的那一个以及其之前的全部弹出并在set中删除
                while (q.front() != s[i])
                {
                    cout<<char_set.erase(q.front())<<endl;
                    q.pop();
                }   
                cout<<char_set.erase(q.front())<<endl;
                q.pop();
            }     
            q.push(s[i]);
            char_set.insert(s[i]);
            max_len = q.size() > max_len ? q.size() : max_len;
        }
        return max_len;
    }

    // 滑动窗口 类似上面的队列 用双指针代替队列
    int lengthOfLongestSubstring3(string s) {
        if (s.empty())
            return 0;
        int left = 0, right = 0, max_len = 0;
        set<int> char_set;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (char_set.find(s[i]) != char_set.end())// 从最左一直删到重复的那个（包括）
            {
                int ind = left;
                while (s[ind] != s[i])
                {
                    char_set.erase(s[ind++]);
                    left++;// 窗口中删除
                }
                char_set.erase(s[ind]);
                left++;// 窗口中删除
            }

            right++;
            char_set.insert(s[i]);
            
            if ((right - left) > max_len)
                max_len = right - left;
        }
        return max_len;
    }

    int lengthOfLongestSubstring(string s) {
        set<int> se;
        int max_res = 0;
        int left = 0, right = 0;
        while (right < s.length())
        {
            // right是要插入的
            if (se.find(s[right]) != se.end())
            {
                while (s[left] != s[right])
                {
                    se.erase(s[left++]);
                }
                se.erase(s[left++]);
                // 删掉了与right重复的
            }
            se.insert(s[right]);
            max_res = max(max_res,right-left+1);
            right++;
        }
        return max_res;
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.lengthOfLongestSubstring("dvdf"));
}