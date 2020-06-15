//#206 反转链表

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 迭代
    ListNode* reverseList2(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = nullptr, *cur = head, *next = nullptr;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* reverseList3(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = nullptr, *cur = head, *next = nullptr;
        while (cur->next != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        cur->next = pre;
        return cur;
    }

    // 递归
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *cur = reverseList(head->next);// 最后一个节点
        head->next->next = head;// 当前节点的下一个(最后一个)指向当前节点
        head->next = nullptr;
        return cur;
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
    s.pringList(s.reverseList(n1));
}