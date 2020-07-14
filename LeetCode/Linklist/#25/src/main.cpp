// 25. K 个一组翻转链表
// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
// k 是一个正整数，它的值小于或等于链表的长度。
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
// 示例：
// 给你这个链表：1->2->3->4->5
// 当 k = 2 时，应当返回: 2->1->4->3->5
// 当 k = 3 时，应当返回: 3->2->1->4->5
// 说明：
// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *p = head;
        int count = 0;
        // 到最后 或者 到了要反转的位置的后一个 第二段的开头
        while (p != nullptr && count < k)// 最后count出来应该是==k
        {
            p = p->next;
            count++;
        }
        // 到了最后一段 不够长度就不需要反转
        if (count < k)
            return head;
        // 此时p指向要反转位置的后一个 第二段的开头
        ListNode *pre = nullptr, *cur = head, *next = nullptr;
        while (cur != p)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = reverseKGroup(p,k);
        return pre;
    }
};

void printList(ListNode *p)
{
    while (p != NULL)
    {
        printf("[%d]->", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution s;
    printList(s.reverseKGroup(n1, 3));
}