//#面试题55-II 平衡二叉树
// 1 <= 树的结点个数 <= 10000
// 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
// 如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

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

static TreeNode* createFromLevelTraverse(vector<int> list)
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
                if (n->left != NULL)
                    q.push(n->left);
            }
            if (ind < list.size())
            {
                n->right = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                ind++;
                if (n->right != NULL)
                    q.push(n->right);
            }
            q.pop();
        }
    }
    return root;
}

class Solution {
public:
    // 1 <= 树的结点个数 <= 10000
    bool balance = true;

    bool isBalanced(TreeNode* root) {       
        depth(root);
        return balance;
    }
    
    int depth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int l_depth = depth(root->left);
        int r_depth = depth(root->right);
        if (1 < abs(l_depth - r_depth))
            balance = false;
        return 1 + max(l_depth,r_depth);
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.isBalanced(createFromLevelTraverse({1,2,2,3,3,NULL,NULL,4,4})));
}