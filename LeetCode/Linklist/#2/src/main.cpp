//#1 两数相加
// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode* head;
        return dfs(l1,l2,head,0);
    }

    ListNode* dfs2(ListNode* l1, ListNode* l2, ListNode* p, int addition)
    {
        if (l1 == nullptr && l2 == nullptr && addition == 0)
            return nullptr;
        int sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + addition;
        
        p = new ListNode(sum % 10);
        p->next = dfs(l1 == nullptr ? nullptr : l1->next,
                      l2 == nullptr ? nullptr : l2->next,
                      p->next,sum / 10);
        return p;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p;
        return dfs(l1,l2,p,0);
    }

    ListNode* dfs(ListNode* l1, ListNode* l2, ListNode* p, int addition)
    {
        if (l1 == nullptr && l2 == nullptr && addition == 0)
            return nullptr;
        int n = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + addition;
        p = new ListNode(n % 10);
        p->next = dfs(l1 == nullptr ? nullptr : l1->next,
                      l2 == nullptr ? nullptr : l2->next,
                      p->next,n / 10);
        return p;
    }
};

int main()
{
    Solution s;
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    ListNode* m1 = new ListNode(5);
    ListNode* m2 = new ListNode(6);
    ListNode* m3 = new ListNode(4);
    m1->next = m2;
    m2->next = m3;
    ListNode* root = s.addTwoNumbers(n1,m1);
    while (root != nullptr)
    {
        printf("%d ",root->val);
        root = root->next;
    }
    
}