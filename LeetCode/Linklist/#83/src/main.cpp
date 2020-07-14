// #83. 删除排序链表中的重复元素
// 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = nullptr, *p = head;
        while (p->next != nullptr)
        {
            if (p->val == p->next->val)
            {
                ListNode *tmp = p->next;  
                p->next = p->next->next;
                delete tmp;
            }
            // 跳过了重复的就不要前进
            else
            {
                p = p->next;   
            }
        }
        return head;
    }
};

int main()
{
    
}