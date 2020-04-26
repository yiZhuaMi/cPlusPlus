//#142 环形链表 II
// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置
// （索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
// 说明：不允许修改给定的链表。
// 不用额外空间

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // x:起点到入口
    // y:入口到相遇点
    // z:相遇点到入口
    // => 第一次相遇时:
    // f = x + y +z
    // s = x + y
    // 由于 f = 2s
    // => 2(x + y) = x + y +z
    // => x = z
    // => f从起点出发走x步一定会与l再走z步相遇在入口
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *low = head;
        while (true)
        {
            if (fast == nullptr || fast->next == nullptr)// 没有环
                return nullptr;
            fast = fast->next->next;
            low = low->next;
            if (fast == low)// 找到了环上的相遇点
                break;
        }
        fast = head;
        while (fast != low)
        {
            fast = fast->next;
            low = low->next;
        }
        return low;
    }

    void pringList(ListNode* head)
    {
        ListNode *p = head;
        while (p != NULL)
        {
            printf("%d->",p->val);
            p = p->next;
        }        
    }
};

int main()
{
    Solution s;
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(1);
    ListNode *n4 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    printf("%d",s.detectCycle(n1)->val);
}