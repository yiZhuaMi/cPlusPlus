//#面试题18 删除链表的节点

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        if (head->val == val)// 也可以new一个节点指向head，这样就不用特殊处理head。
            head = head->next;
        ListNode *p = head;
        while (p != nullptr && p->next != nullptr)
            if (p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        return head;
    }

    void printList(ListNode* head)
    {
        ListNode* p = head;
        while (p != NULL)
        {
            cout<<p->val<<"->";
            p = p->next;
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(3);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(1);
    ListNode* l4 = new ListNode(1);
    ListNode* l5 = new ListNode(1);
    head->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    s.printList(head);
    s.printList(s.deleteNode(head,1));
}