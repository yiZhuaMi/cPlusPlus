//#19 删除链表的倒数第N个节点
// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
// 给定的 n 保证是有效的。
// 进阶：你能尝试使用一趟扫描实现吗？

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *h = new ListNode(-1);// 新头节点
        h->next = head;// 指向原始头节点
        ListNode *fast = head, *slow = head, *pre = h;
        while (n - 1> 0)// 给定的 n 保证是有效的。所以这里无需判断为空
        {
            fast = fast->next;
            n--;
        }
        while (fast->next != nullptr)// 让fast指向最后一个 slow最快就是fast
        {
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;// slow本身不会null
        return h->next;
    }
};

void printList(ListNode* p)
{
    while (p != NULL)
    {
        printf("[%d]->",p->val);
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
    printList(s.removeNthFromEnd(n1, 2));
    
}