#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isBST(TreeNode* root)
{
    if (root == nullptr)
        return true;
    if (root->left != nullptr && root->left->val >= root->val)
        return false;
    if (root->right != nullptr && root->right->val <= root->val)
        return false;
    return isBST(root->left) && isBST(root->right);
}

ListNode* moveLinkList(ListNode* head, int val)
{
    if (head == nullptr)
        return;
    ListNode* h_lag = new ListNode(-1);
    ListNode* h_sma = new ListNode(-1);
    ListNode* h_equ = new ListNode(-1);
    ListNode *p = head, *p_l = h_lag, *p_s = h_sma, *p_e = h_equ;
    while (p != nullptr)
    {
        if (p->val > val)
        {
            p_l->next = p;
            p_l = p_l->next;
        }
        else if (p->val < val)
        {
            p_s->next = p;
            p_s = p_s->next;
        }
        else
        {
            p_e ->next = p;
            p_e = p_e->next;
        }
        p = p->next;
    }
    head = h_sma->next;
    p_s->next = h_equ->next;
    p_e->next = h_lag->next;
    
    return head;
}

int main() {
    vector<int> v = {1,4,7,3,0,2,8};
    int k = 4;
}