// #814 二叉树剪枝

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
    TreeNode* createFromLevelTraverse(vector<int> list)
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
                    n->left = list[ind] == -1 ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->left != nullptr)
                        q.push(n->left);
                }
                if (ind < list.size())
                {
                    n->right = list[ind] == -1 ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->right != nullptr)
                        q.push(n->right);
                }
                q.pop();
            }
        }
        return root;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr || !existOne(root))
            return nullptr;
        root->right = pruneTree(root->right);// 若子树包含1，将其送入剪枝
        root->left = pruneTree(root->left);
        return root;
    }

    bool existOne(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        if (root->val == 1)
            return 1;
        return existOne(root->left) + existOne(root->right);// 只要子树中有一个节点为1，返回>0
    }
};

int main()
{
   Solution s;
   vector<int> v = {1,1,0,1,1,0,1,0};
   TreeNode *root = s.createFromLevelTraverse(v);
   root = s.pruneTree(root);
   1;
}