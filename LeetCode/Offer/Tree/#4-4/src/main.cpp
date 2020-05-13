//#面试题04.04 检查平衡性
// 实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。

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

    bool balance = true;
    bool isBalanced(TreeNode* root) {
        depth(root);
        return  balance;
    }

    int depth(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        
        int dp_left = depth(root->left);
        int dp_right = depth(root->right);
        
        if (1 < abs(dp_left - dp_right))
        {
            balance = false;
        }
        
        return 1 + max(dp_left,dp_right);
    }

};

int main()
{   
    Solution s;
    printf("%d\n",s.isBalanced(s.createFromLevelTraverse({1,2,2,3,3,NULL,NULL,4,4})));
}