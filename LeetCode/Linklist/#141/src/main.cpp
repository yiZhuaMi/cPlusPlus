//#141 环形链表

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 空间复杂度:O(n)
    bool hasCycle2(ListNode *head) {
        set<ListNode*> s;
        ListNode *p = head;
        while (p != nullptr)
        {
            if (!s.insert(p).second)
                return true;
            p = p->next;
        }
        return false;
    }
    
    // 空间复杂度:O(1)
    // 把慢跑者视作参考系，这样来思考，慢跑者站着不动，快跑者速度为1，就会发现一定会相遇
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        // 跑得慢的在后，跑得快的在前
        ListNode *low = head, *fast = head->next;
        while (low != nullptr && fast != nullptr && fast->next != nullptr)// 会=null则不会有环
        {
            if (low == fast)
                return true;
            low = low->next;
            fast = fast->next->next;// 若有环 low fast总会重合     
        }
        return false;
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
    n4->next = n1;
    printf("%d",s.hasCycle(n1));
}