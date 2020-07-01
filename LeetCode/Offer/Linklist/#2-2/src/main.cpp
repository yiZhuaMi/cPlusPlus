// #面试题 02.02 返回倒数第 k 个节点
// 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
// 注意：本题相对原题稍作改动
// 示例：
// 输入： 1->2->3->4->5 和 k = 2
// 输出： 4

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode *fast = head, *low = head;
        while (--k)
        {
            fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            low = low->next;
        }
        return low->val;
    }
};

int main()
{
    Solution s;
    // s.getIntersectionNode();
}