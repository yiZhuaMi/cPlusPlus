// 1282. 用户分组
// 有 n 位用户参加活动，他们的 ID 从 0 到 n - 1，每位用户都 恰好 属于某一用户组。给你一个长度
// 为 n 的数组 groupSizes，其中包含每位用户所处的用户组的大小，请你返回用户分组情况（存在的用户组以及每个组中用户的 ID）。
// 你可以任何顺序返回解决方案，ID 的顺序也不受限制。此外，题目给出的数据保证至少存在一种解决方案。
// 输入：groupSizes = [3,3,3,3,3,1,3]
// 输出：[[5],[0,1,2],[3,4,6]]
// 解释： 
// 其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
// 贪心算法
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople2(vector<int>& groupSizes) {
        vector<vector<int>> res;
        for (int i = 0; i < groupSizes.size(); i++)
        {
            bool new_group = true;
            for (int j = 0; j < res.size(); j++)// 在res中的组找到还有位置的
                if (res[j].size() < groupSizes[res[j][0]] && // 这一组还有空位置&&目标组员数量相等
                    groupSizes[i] == groupSizes[res[j][0]])// groupSizes[第j组第一个] = 这一组的容量
                {
                    res[j].push_back(i);
                    new_group = false;
                    break;
                }
            if (new_group)
                res.push_back({i});
        }
        return res;
    }
};
    
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int,vector<int>> m;// <目标成员数,成员>
        // 先把所有目标相同的都放一个组
        for (int i = 0; i < groupSizes.size(); i++)
        {
            m[groupSizes[i]].push_back(i);
        }
        // 拆分超出容量的组
        for (auto ite = m.begin(); ite != m.end(); ++ite)// 组
        {
            for (auto v = ite->second.begin(); v != ite->second.end(); v += ite->first)
            {
                res.push_back(vector<int>(v,v+ite->first));
            }
        }
        return res;
    }
    
int main()
{
    Solution s;
}