// #328 奇偶链表
// 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

// 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

// 示例 1:

// 输入: 1->2->3->4->5->NULL
// 输出: 1->3->5->2->4->NULL
// 示例 2:

// 输入: 2->1->3->5->6->4->7->NULL 
// 输出: 2->3->6->7->1->5->4->NULL
// 说明:

// 应当保持奇数节点和偶数节点的相对顺序。
// 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int flag = 1;
        // 指向偶数串的头节点
        ListNode* h2 = new ListNode(-1);
        ListNode *pre = head, *p2 = h2, *cur = head;
        while (cur != nullptr)
        {
            if (flag++ % 2 == 1)
            {
                // 偶数时，偶数节点被删除，pre不用移动
                pre = cur;// !!!!!!
                // 最后一个节点是奇数时（此时p2->next指向最后一个奇数节点）
                if (cur->next == nullptr)
                    p2->next = nullptr;
            }
            else
            {
                // next = cur->next;
                // 奇数串 前后相连 跳过偶数
                pre->next = cur->next;
                // 偶数串指针指向偶数
                p2->next = cur;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        // 此时pre指向最后一个奇数
        pre->next = h2->next;
        return head;
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
    Solution s;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    printList(n1);
    s.oddEvenList(n1);
    printList(n1);
}