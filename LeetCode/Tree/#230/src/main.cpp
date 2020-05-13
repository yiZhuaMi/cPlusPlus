//#230 二叉搜索树中第K小的元素

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
                    if (n->left != nullptr)// 重点是不为空的才放入队列找子树
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

    //  中序遍历 递归
    int kk;
    int res;

    int kthSmallest2(TreeNode* root, int k) {
        kk = k;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root)
    {
        if (root ==  nullptr || kk <= 0)
            return;
        dfs(root->left);

        if (--kk == 0)
        {
            res = root->val;
            return;
        }
        
        dfs(root->right);
    }

    // 迭代 中序遍历 左臂入栈
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root != nullptr)
        {
            s.push(root);
            root = root->left;
        }
        while (!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            if (--k == 0)
                return node->val;
            // 右子树
            node = node->right;
            while (node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.kthSmallest(s.createFromLevelTraverse({1,NULL,2}),2));
}