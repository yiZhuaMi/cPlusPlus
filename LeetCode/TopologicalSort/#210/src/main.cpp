// #210 课程表 II
// 现在你总共有 n 门课需要选，记为 0 到 n-1。
// 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
// 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
// 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
// 示例 1:
// 输入: 2, [[1,0]] 
// 输出: [0,1]
// 解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    // 拓扑排序
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        // 图 每一行代表一条边 {被依赖的课->依赖前者的课}
        vector<vector<int>> g(numCourses);
        // 记录课程的入度，也就是未就绪的依赖课程数 <课程编号，入度／未就绪的依赖课程数>
        unordered_map<int,int> m;
        // 就绪队列 入队：课程就绪 出队：课程完成
        queue<int> q;
        for (auto c : prerequisites)
        {
            // 这门课程依赖的课数量+1
            m[c[0]]++;
            // 新增一条边 从 被依赖的课->依赖前者的课
            g[c[1]].push_back(c[0]);
        }
        // 将入度为0／就绪的课程入队
        for (int i = 0; i < numCourses; i++)
            if (m[i] == 0)
                q.push(i);
        // 如果一开始队列中有2门课程，那么第二次进入循环时第二个push进res的岂不是搞错了？？？？
        // 因为必须修完所有课，所以一开始两门课都必须在res中，不一定要马上修他的后继。
        while (!q.empty())
        {
            int lesaon = q.front();
            q.pop();
            res.push_back(lesaon);
            // 将所有依赖lesaon的课程的依赖数-1
            for (int i = 0; i < g[lesaon].size(); i++)
            {
                // 依赖需要减少的课程
                int l = g[lesaon][i];
                // 就绪则加入队列
                if (--m[l] == 0)
                    q.push(l);
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};
    
int main()
{
    Solution s;
    vector<vector<int>> v = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> res = s.findOrder(4,v);
    for (auto c : res)
        printf("%d ",c);
}