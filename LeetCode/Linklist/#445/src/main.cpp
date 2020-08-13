// #445 两数相加 II
// 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
// 进阶：
// 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
// 示例：

// 输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 8 -> 0 -> 7

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1->val == 0 || l2->val == 0)
            return l1->val == 0 ? l2 : l1;
        // 先将所有节点分别入栈
        stack<int> s1, s2;
        while (l1 != nullptr)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int addition = 0;
        ListNode *res = nullptr;
        // 再依次出栈 相加
        while (!s1.empty() || !s2.empty() || addition != 0)
        {
            int n1 = 0;
            if (!s1.empty())
            {
                n1 = s1.top();
                s1.pop();
            }
            int n2 = 0;
            if (!s2.empty())
            {
                n2 = s2.top();
                s2.pop();
            }
            int sum = n1 + n2 + addition;
            addition = sum / 10;
            ListNode *cur = new ListNode(sum % 10);
            cur->next = res;
            res = cur;
        }
        return res;
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