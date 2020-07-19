// #56. 合并区间
// 给出一个区间的集合，请合并所有重叠的区间。
// 示例 1:
// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2:
// 输入: [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // {{1,4},{1,4}}失败
    vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        vector<char> v(intervals[intervals.size()-1][1] + 1);
        map<int,char> m;
        
        for (int i = 0; i < intervals.size(); i++)
        {
            for (int j = 0; j < intervals[i].size(); j++)
            {
                // [1,4][4,5] 重复的两个都去掉
                if (m.find(intervals[i][j]) == m.end())
                    m[intervals[i][j]] = j == 0 ? '[' : ']';
                else
                    m.erase(intervals[i][j]);
                
            }
        }

        // 待匹配左括号数量
        int left_num = 0;
        vector<int> ans;
        for (auto ite = m.begin(); ite != m.end(); ite++)
        {
            if (ite->second == '[')
            {
                ans.push_back(ite->first);
                left_num++;
            }
            // ']'
            else
            {
                // 被消去合并
                if (left_num > 1)
                {
                    ans.pop_back();
                }
                // 结果区间
                else
                {
                    ans.push_back(ite->first);        
                }               
                left_num--;
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < ans.size(); i+=2)
            res.push_back({ans[i],ans[i+1]});
        return res;
    }

    // 对 vector<vector<int>> 排序，需要按照先比较区间开始，如果相同再比较区间结束，使用默认的排序规则即可
    // 使用双指针，左边指针指向当前区间的开始
    // 使用一个变量来记录连续的范围 t
    // 右指针开始往后寻找，如果后续的区间的开始值比 t 还小，说明重复了，可以归并到一起
    // 此时更新更大的结束值到 t
    // 直到区间断开，将 t 作为区间结束，存储到答案里
    // 然后移动左指针，跳过中间已经合并的区间
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();) {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], t });
            i = j;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> v = {{1,4},{4,5}};
    s.merge(v);
}