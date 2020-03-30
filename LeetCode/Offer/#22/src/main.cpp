//#面试题22 链表中倒数第k个节点

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        
        if (head == NULL)
            return head;        

        int len = 0;
        ListNode* p = head;
        while (p != NULL)
        {
            len++;
            p = p->next;
        }
        p = head;
        for (int i = 0; i <= len-k-1; i++)
            p = p->next;
        return p;
    }
    // 快慢指针
    ListNode* getKthFromEnd2(ListNode* head, int k) {
        
        if (head == NULL)
            return head;        
        ListNode *fast = head, *low = head;
        while (k-- > 0 && fast != NULL)
            fast = fast->next;
        while (fast != NULL)
        {
            fast = fast->next;
            low = low->next;
        }
        return low;
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
    ListNode* head = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    head->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    s.printList(head);
    s.printList(s.getKthFromEnd2(head,2));
}