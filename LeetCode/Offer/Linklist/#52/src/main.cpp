//#面试题52 两个链表的第一个公共节点

#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode *pa = headA, *pb = headB;
        while (pa != nullptr && pb != nullptr)
        {
            if (!s.insert(pa).second)
                return pa;
            pa = pa->next;
            if (!s.insert(pb).second)
                return pb;
            pb = pb->next;
        }
        pa = pa == nullptr ? pb : pa;
        while (pa != nullptr)
        {
            if (!s.insert(pa).second)
                return pa;
            pa = pa->next;
        }
        return nullptr;
    }

    // 两个链表长度分别为L1+C、L2+C，C为公共部分的长度
    // 第一个人走了L1+C步后，回到第二个人起点走L2步
    // 第2个人走了L2+C步后，回到第一个人起点走L1步
    // 当两个人走的步数都为L1+L2+C时就相遇
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2)// 若不相交 都走完L1+L2时同时为NULL
        {
            p1 = p1 != nullptr ? p1->next : headB;
            p2 = p2 != nullptr ? p2->next : headA;            
        }
        return p1;
    }
};

int main()
{
    Solution s;
    // s.getIntersectionNode();
}