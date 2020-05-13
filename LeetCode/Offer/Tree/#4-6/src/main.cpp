//#面试题04.06 后继者
// 设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
// 如果指定节点没有对应的“下一个”节点，则返回null。

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
        {
            return nullptr;
        }
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

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr || p ==nullptr)
            return nullptr;
        
        if (p->val < root->val)// 后继节点在左子树中 若没有找到则后继就是root
        {
            TreeNode* node = inorderSuccessor(root->left,p);
            return node == nullptr ? root : node;
        }
        else// (p->val >= root->val)// 后继节点在右子树中 肯定能找到
        {
            return inorderSuccessor(root->right,p);
        }
    }
};

int main()
{   
    Solution s;
    printf("%d\n",s.inorderSuccessor(s.createFromLevelTraverse({5,3,6,2,4,NULL,NULL,1}),new TreeNode(5))->val);
}