// 234 回文链表
// 请判断一个链表是否为回文链表。

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
    // 找到前半部分链表的尾节点。
    // 反转后半部分链表。
    // 判断是否为回文。
    bool isPalindrome(ListNode* head) {
        if (head ==  nullptr || head->next ==  nullptr)
            return true;
        ListNode *fast = head, *low = head;
        while (low != nullptr && fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            low = low->next;
        }
        // low指向后半部分开头（偶数） 或者 中间节点（奇数）（就算加上中间节点以其反转，它会变成的最后一个，不影响下面判等）
        ListNode *cur = low, *pre = nullptr, *next = nullptr;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode *p1 = head, *p2 = pre;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        // 如果是奇数，最后p1为空，p2指向中间节点
        return true;
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
    s.deleteNode(n1,n3);
}