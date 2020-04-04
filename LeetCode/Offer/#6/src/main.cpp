//#面试题6 从尾到头打印链表

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
    vector<int> reversePrint(ListNode* head) {
        if (head == NULL) return {};
        vector<int> v, w;
        ListNode *p = head;
        v.push_back(p->val);
        while (p->next != NULL)
        {
            p = p->next;
            v.push_back(p->val);
        }
        //使用algorithm算法中的reverse反转res
        // reverse(v.begin(),v.end());
        for (int i = v.size()-1; i >= 0; i--)
            w.push_back(v[i]);
        return w;
    }
    vector<int> reversePrint2(ListNode* head) {
        if(!head)
            return {};
        vector<int> a=reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};

int main()
{   
    ListNode *head = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    head->next = n1;
    n1->next = n2;
    
    Solution s;
    vector<int> v = s.reversePrint(head);
    cout<<"[";
    for (size_t i = 0; i < v.size()-1; i++)
        printf("%d,",v[i]);
    cout<<v[v.size()-1]<<"]";

    
}