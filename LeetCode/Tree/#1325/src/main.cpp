// #1325 删除给定值的叶子节点
// 给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。
// 注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。
// 也就是说，你需要重复此过程直到不能继续删除。

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

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr)
            return nullptr;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if (root->val == target && root->left == nullptr && root->right == nullptr)
            return nullptr;
        return root;
    }
};

int main()
{
   Solution s;
   TreeNode *root = s.removeLeafNodes(s.createFromLevelTraverse({1,3,3,3,2}),3);
   1;
}