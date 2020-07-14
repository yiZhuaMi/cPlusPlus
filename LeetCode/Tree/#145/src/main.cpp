//#145 二叉树的后序遍历

#include <iostream>
#include <vector>
#include <stack>
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
    TreeNode* create(vector<int> list, int ind, bool left_null)
    {
        if (ind >= list.size() || list[ind] == NULL)
            return NULL;
        TreeNode *n = new TreeNode(list[ind]);
        if (left_null)
        {
            n->left = create(list,ind+1,left_null);
            n->right = create(list,ind+2,n->left==NULL);
        }
        else
        {
            n->left = create(list,2*ind+1,left_null);
            n->right = create(list,2*ind+2,n->left==NULL);
        }
        return n;
    }

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

    // 递归
    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> v;
        func(root,v);
        return v;
    }

    void func(TreeNode* root, vector<int>& v)
    {
        if (root == NULL)
            return;
        func(root->left,v);
        func(root->right,v);
        v.push_back(root->val);
    }

    // 颜色标记法
    vector<int> postorderTraversal(TreeNode* root) {
        int white = 0, gray = 1;
        stack<pair<int,TreeNode*>> s;
        vector<int> v;
        s.push(pair<int,TreeNode*>(white,root));
        while (!s.empty())
        {   
            int color = s.top().first;
            TreeNode *n = s.top().second;
            s.pop();
            if (n == NULL)
                continue;
            if (color == white)
            {
                s.push(pair<int,TreeNode*>(gray,n));
                s.push(pair<int,TreeNode*>(white,n->right));
                s.push(pair<int,TreeNode*>(white,n->left));
            }
            else
                v.push_back(n->val);
        }
        return v;        
    }

    // 前序递归方法，左右先后入栈，相当于 根右左 遍历，最后反转vector变成左右根
};

int main()
{
    Solution s;
    // vector<int> v = {1,NULL,2,NULL,NULL,3};
    vector<int> v = {1,NULL,2,3};
    TreeNode *root = s.createFromLevelTraverse(v);
    v = s.postorderTraversal(root);
}