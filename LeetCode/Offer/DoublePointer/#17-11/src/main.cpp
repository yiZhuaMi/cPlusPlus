// #面试题 17.11. 单词距离
// 有个内含单词的超大文本文件，给定任意两个单词，找出在这个文件中这两个单词的最短距离(相
// 隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?
// 示例：
// 输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
// 输出：1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 先找1，再往右找2，计算距离，再往右找1。。。
    int findClosest(vector<string>& words, string word1, string word2) {
        int left = 0, right = 0;
        // flag:0 = 左边没有待匹配的， 1 = 左边待匹配的是word1， 2 = 左边待匹配的是word2
        int res = INT32_MAX, flag = 0;
        while (right < words.size())
        {
            if (words[right] == word1)
            {
                if (flag == 2)
                    res = min(res,right-left);
                flag = 1;
                // 左指针右移到word1的位置
                left = right;
            }
            else if (words[right] == word2)
            {
                if (flag == 1)
                    res = min(res,right-left);
                flag = 2;
                left = right;
            }
            right++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> w = {"I","am","a","student","from","a","university","in","a","city"};
    printf("%d",s.findClosest(w,"a","student"));
}