// #1315 祖父节点值为偶数的节点和

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 层序遍历建树
    TreeNode* createFromLevelTraverse1(vector<int> list)
    {
        if (list.empty())
            return NULL;
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(list[0]);
        q.push(root);
        int ind = 1;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *n = q.front();
                if (ind < list.size())
                {
                    n->left = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->left != nullptr)
                        q.push(n->left);
                }
                if (ind < list.size())
                {
                    n->right = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->right != nullptr)
                        q.push(n->right);
                }
                q.pop();
            }
        }
        return root;
    }

    TreeNode* createFromLevelTraverse(vector<int> list)
    {
        if (list.empty())
            return nullptr;
        
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(list[0]);
        q.push(root);
        int ind = 1;
        while (!q.empty())
        {
            int len = q.size();
            for (size_t i = 0; i < len; i++)
            {
                TreeNode *n = q.front();
                
                if (ind < list.size())
                {
                    n->left = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->left != nullptr)
                        q.push(n->left);
                }
                
                if (ind < list.size())
                {
                    n->right = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->right != nullptr)
                        q.push(n->right);
                }
                
                q.pop();
            }
            
        }
        return root;
    }

    int sumEvenGrandparent(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (size_t i = 0; i < len; i++)
            {
                TreeNode *n = q.front();
                if (n->left != nullptr)
                {
                    q.push(n->left);
                    if (n->val % 2 == 0)
                    {
                        if (n->left->left != nullptr)
                            sum += n->left->left->val;
                        if (n->left->right != nullptr)
                            sum += n->left->right->val;
                    }
                    
                }
                if (n->right != nullptr)
                {
                    q.push(n->right);
                    if (n->val % 2 == 0)
                    {
                        if (n->right->left != nullptr)
                            sum += n->right->left->val;
                        if (n->right->right != nullptr)
                            sum += n->right->right->val;
                    }
                }
                q.pop();
            }
        }
        return sum;
    }
};

int main()
{
   Solution s;
   vector<int> v = {61,13,46,NULL,NULL,NULL,56,72};
   TreeNode *root = s.createFromLevelTraverse(v);
   cout<<s.sumEvenGrandparent(root);
}