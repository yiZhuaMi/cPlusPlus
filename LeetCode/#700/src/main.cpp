// #700 二叉搜索树中的搜索

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

    // 递归
    TreeNode* searchBST2(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;
        
        if (val > root->val)
        {
            return searchBST(root->right,val);
        }
        else if (val < root->val)
        {
            return searchBST(root->left,val);
        }
        else
            return root;
    }

    // 迭代
    TreeNode* searchBST(TreeNode* root, int val) {
        while (true)
            if (root == nullptr)
                return nullptr;
            else if (val > root->val)
                root = root->right;
            else if (val < root->val)
                root = root->left;
            else
                return root;
    }
};

int main()
{
   Solution s;
   vector<int> v = {4,2,7,1,3};
   TreeNode *root = s.createFromLevelTraverse(v);
   root = s.searchBST(root,2);
   1;
}