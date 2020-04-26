//#876 链表的中间结点

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode *p1 = head, *p2 = head;
        while (p1 != nullptr && p2 != nullptr && p2->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    
    void pringList(ListNode* head)
    {
        ListNode *p = head;
        while (p != NULL)
        {
            printf("%d->",p->val);
            p = p->next;
        }      
        cout<<endl;  
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
    s.pringList(n1);
    printf("%d\n",s.middleNode(n1)->val);
}