//#面试题25 合并两个排序的链表

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;        
        ListNode *pHead = new ListNode(-1);
        ListNode *p = pHead;
        // 两个指针分别指向l1，l2，把更小的节点加入新链表，并后移，再比较。
        while (p1 != NULL || p2 != NULL)
        {
            ListNode *new_node;
            if (p1 != NULL && p2 != NULL)
            {
                new_node = new ListNode(p1->val <= p2->val ? 
                                        p1->val : p2->val);
                p1->val <= p2->val ? p1=p1->next : p2=p2->next;                
            }
            else if (p1 != NULL)
            {
                new_node = new ListNode(p1->val);
                p1 = p1->next;
            }
            else//p2 != NULL
            {
                new_node = new ListNode(p2->val);
                p2 = p2->next;
            }
            p->next = new_node;
            p = p->next;
        }
        return pHead->next;
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
    //leetcode中链表默认没有头结点
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(3);
    ListNode *n3 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    ListNode *n4 = new ListNode(2);
    ListNode *n5 = new ListNode(4);
    ListNode *n6 = new ListNode(6);
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    Solution s;
    printList(s.mergeTwoLists(n1, n4));
    
}