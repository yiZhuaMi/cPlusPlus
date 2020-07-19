// #86 分隔链表
// 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
// 你应当保留两个分区中每个节点的初始相对位置。
// 示例:
// 输入: head = 1->4->3->2->5->2, x = 3
// 输出: 1->2->2->4->3->5

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 理论上只需要x后面小于x的才移动，但这里直接把链表拆成两个部分。
    // l1:所有<x的节点 l2:所有>=x的节点
    // 最后l1—>next = l2
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        // lh记录小于x的节点
        ListNode *lh = new ListNode(-1);
        ListNode *lp = lh;
        // gh记录>=x的节点
        ListNode *gh = new ListNode(-1);
        ListNode *gp = gh;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                // lp->next = head;
                lp->next = new ListNode(head->val);
                lp = lp->next;
            }
            else
            {
                // gp->next = head;
                gp->next = new ListNode(head->val);
                gp = gp->next;
            }
            head = head->next;
        }
        lp->next = gh->next;
        return lh->next;
    }
};

int main()
{
    
}