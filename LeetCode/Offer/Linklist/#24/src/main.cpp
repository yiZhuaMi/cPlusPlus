//#面试题24 反转链表

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList2(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *p1 = head, *p2, *p3;
        if (p1->next == NULL)
            return p1;
        else if (p1->next->next == NULL)
        {
            p2 = p1->next;
            p2->next = p1;
            p1->next = NULL;
            return p2;
        }
        else
        {
            p2 = p1->next;
            p3 = p1->next->next;
            while (p3 != NULL)
            {  
                p2->next = p1;//反向
                //3个指针都向后移一位
                p1 = p2;
                p2 = p3;
                p3 = p3->next;                
            }
            p2->next = p1;
            head->next = NULL;
            return p2;
        }       
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *cur = head, *next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;    
        }
        return pre;
    }
};

int main()
{   
    ListNode *head = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    head->next = n1;
    n1->next = n2;
    
    Solution s;
    ListNode *l = s.reverseList(head);
    while (l != NULL)
    {
        printf("%d->",l->val);
        l = l->next;
    }
}