#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void zhongxu_digui(TreeNode *root)
    {
        if (root == nullptr)
            return;
        zhongxu_digui(root->left);
        printf("%d ",root->val);
        zhongxu_digui(root->right);
    }

    vector<int> zhongxu_yanse(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> res;
        stack<pair<TreeNode*,int>> s;
        int red = 0, green = 1;
        s.push(pair<TreeNode*,int>(root,red));
        while (!s.empty())
        {
            TreeNode *node = s.top().first;
            int color = s.top().second;
            s.pop();
            if (node == nullptr)
                continue;
            // 白色 遍历
            if (color == green)
            {
                res.push_back(node->val);
            }
            // 灰色 入栈
            else
            {
                s.push(pair<TreeNode*,int>(node->right,red));
                s.push(pair<TreeNode*,int>(node,green));
                s.push(pair<TreeNode*,int>(node->left,red));
            }            
        }
        return res;
    }

    // 左臂入栈法
    // 现将root和其整个左子树依次入栈，然后开始pop，每pop出一个就遍历，
    // 同时检查这个结点是否有右子树，如果有就将右子树的左臂入栈，以此类推。
    vector<int> zhongxu_zuobiruzhan(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        stack<TreeNode*> s;
        vector<int> res;
        // 根节点左臂入栈
        while (root != nullptr)
        {
            s.push(root);
            root = root->left;
        }
        // 到底开始pop
        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            // 遍历
            res.push_back(node->val);
            // 右子树进行左臂入栈
            node = node->right;
            while (node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
        }
        return res;
    }

    // 二叉搜索树的最近公共祖先
    TreeNode* zuijinzuxian(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (p->val < root->val && q->val < root->val)
            return zuijinzuxian(root->left,p,q);
        else if (p->val > root->val && q->val > root->val)
            return zuijinzuxian(root->right,p,q);
        else
            return root;
    }

    // 二叉搜索树的最近公共祖先
    TreeNode* zuijinzuxian(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        
    }
};