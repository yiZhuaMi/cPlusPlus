// #617 合并二叉树

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

    // 不修改原树
    TreeNode* mergeTrees2(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
            return nullptr;
        if (t1 != nullptr && t2 != nullptr)
        {
            TreeNode *root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left,t2->left);// 递归下去所有的其他节点返回到这里 不用额外root
            root->right = mergeTrees(t1->right,t2->right);
            return root;
        }
        return t1 == nullptr ? t2 : t1;// 其中一个不为空
    }

    // 原地合并
    // 时间复杂度：O(N)，其中 N 是两棵树中节点个数的较小值。
    // 空间复杂度：O(N)，在最坏情况下，会递归 N 层，需要 O(N) 的栈空间。
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
            return nullptr;
        if (t1 != nullptr && t2 != nullptr)
        {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left,t2->left);
            t1->right = mergeTrees(t1->right,t2->right);
            return t1;
        }
        return t1 == nullptr ? t2 : t1;// 其中一个不为空
    }
};

int main()
{
   Solution s;
   vector<int> v1 = {1,3,2,5};
   TreeNode *root1 = s.createFromLevelTraverse(v1);
   vector<int> v2 = {2,1,3,NULL,4,NULL,7};
   TreeNode *root2 = s.createFromLevelTraverse(v2);
   TreeNode *root_merge = s.mergeTrees(root1,root2);
   1;
}