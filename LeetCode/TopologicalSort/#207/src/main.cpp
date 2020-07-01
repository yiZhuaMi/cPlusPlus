// #207 课程表
// 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
// 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
// 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
// 示例 1:
// 输入: 2, [[1,0]] 
// 输出: true
// 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // 拓扑排序
    // 起初让 入度为 0 的课 入列
    // 然后逐个出列，课出列 即 课被选 ，并 减小相关课的入度
    // 判定是否有 入度新变为 0 的课，安排入列、再出列
    // 直到没有 入度为 0 的课 可入列
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 记录课程的入度(依赖项的个数) <课的编号,课的入度>
        unordered_map<int,int> m;
        // 就绪课程队列。入队代表就绪，出队代表上完。
        queue<int> q;
        // 图。每一行标识一个箭头{ 被依赖的课 -> 依赖前者的课 }
        vector<vector<int>> g(numCourses);
        // 统计上过的课
        int count = 0;
        // 通过遍历先决条件表，计算出每门课的初始入度
        for (auto c : prerequisites)
        {
            m[c[0]]++;
            g[c[1]].push_back(c[0]);
        }
        // 遍历所有课程，将入度为0也就是就绪的课程入队
        for (int i = 0; i < numCourses; i++)
            if (m[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int lesaon = q.front();
            q.pop();
            count++;
            // 遍历所有依赖lesaon的课程
            for (int i = 0; i < g[lesaon].size(); i++)
            {
                // 依赖将减少的课程
                int l = g[lesaon][i];
                if (--m[l] == 0)
                    q.push(l);
            }
        }
        return count == numCourses;
    }
};
    
int main()
{
    Solution s;
    vector<vector<int>> v = {{1,0},{1,2},{0,1}};
    printf("%d\n",s.canFinish(3,v));
}