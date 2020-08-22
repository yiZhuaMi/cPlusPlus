// #82 删除排序链表中的重复元素 II
// 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
// 示例 1:
// 输入: 1->2->3->3->4->4->5
// 输出: 1->2->5

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 重复
class Solution {
public:
    // 每次删除重复的后一个，重复的第一个等到else／不重复的里面去删除
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode *pre = h, *cur = h->next;
        bool rep = false;
        while (cur->next != nullptr)
        {
            // 跳过了重复的就不要前进
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
                rep = true;
            }
            else
            {
                // 跳过最后剩下的一个重复的
                if (rep)
                    pre->next = cur->next;
                // 正常推进
                else
                    pre = cur;
                cur = cur->next;
                rep = false;
            }
        }
        // 链表末尾的节点也是重复的需要删除
        if (rep)
            pre->next = cur->next;  
                  
        return h->next;
    }
};

int main()
{
    
}