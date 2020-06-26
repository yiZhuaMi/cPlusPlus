// #61. 旋转链表
// 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        // 先求长度
        int len = 1;
        ListNode *p0 = head;
        while (p0->next != nullptr)
        {
            len++;
            p0 = p0->next;
        }
        // 此时p0指向最后一个节点
        k %= len;
        if (k == 0)
            return head;        
        // 找到要成为新头节点的前一个
        ListNode *p_n = head;
        // 由于之前求得了长度，所以不需要快慢指针了
        int step = len - k - 1;
        while (step-- > 0 && p_n != nullptr)
            p_n = p_n->next;
        // 此时p_n为前一段最后一个节点，指向新头节点
        ListNode *h = p_n->next;
        p_n->next = nullptr;
        p0->next = head;
        return h;
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

    Solution s;
    printList(s.rotateRight(n1,3));
    
}