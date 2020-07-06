// #23. 合并K个排序链表
// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
// 示例:
// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 小根堆的回调函数
struct cmp
{  
    bool operator()(ListNode *a,ListNode *b) {return a->val > b->val;}
};

class Solution {
public:
    // 优先队列
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        // 每个链表的头节点加入优先队列
        for (auto l : lists)
            if (l != nullptr)
                q.push(l);

        ListNode *h = new ListNode(-1), *p = h;
        while (!q.empty())
        {
            ListNode* n = q.top();
            q.pop();
            p->next = n;// 添加堆顶n
            p = p->next;// p指向n
            if (p->next != nullptr)
                q.push(p->next);// 将n的next入队
        }
        return h->next;
    }
};

int main()
{
    Solution s;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    ListNode* m1 = new ListNode(2);
    ListNode* m2 = new ListNode(4);
    ListNode* m3 = new ListNode(6);
    m1->next = m2;
    m2->next = m3;

    vector<ListNode*> v = {n1,m1};
    ListNode* root = s.mergeKLists(v);
    while (root != nullptr)
    {
        printf("%d ",root->val);
        root = root->next;
    }
    
}