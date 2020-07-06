//#148 排序链表

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 归并排序
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)// !!!!!!
            return head;
        ListNode* pre_slow = head, *slow = head, *fast = head;
        // 快慢指针找中点
        while (fast != NULL && fast->next != NULL)
        {
            pre_slow = slow;// 最前 ！！！
            slow = slow->next;
            fast = fast->next->next;
        }
        pre_slow->next = NULL;// slow指针的前一个的next置NULL 拆分 ！！！！
        return merge(sortList(head),sortList(slow));
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode *h = new ListNode(-1);// 要构造的有序链表
        ListNode *p = h;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)// 小的插入tmp链表
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 == NULL ? l2 : l1;// 把剩下的追加
        return h->next;
    }
    
    ListNode* s2ortList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *fast = head, *slow = head, *pre_slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            pre_slow = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre_slow->next = nullptr;
        return me2rge(s2ortList(head),s2ortList(slow));
    }

    ListNode* me2rge(ListNode* l1, ListNode* l2) {
        ListNode *h = new ListNode(-1), *p = h;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 == nullptr ? l2 : l1;
        return h->next;
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
    s.pringList(s.sortList(n1));
}