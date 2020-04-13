//#144 二叉树的前序遍历

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
        if (ind >= list.size() || list[ind] == 0)
            return NULL;
        TreeNode *n = new TreeNode(list[ind]);// v中的NULL转换为0 这里会变成叶子结点0
        if (left_null)
        {
            n->left = create(list,ind+1,false);            
            n->right = create(list,ind+2,n->left==NULL);
        }
        else
        {
            n->left = create(list,2*ind+1,false);            
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
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> v;
        func(root,v);
        return v;
    }

    void func(TreeNode* root, vector<int>& v)
    {
        if (root == NULL)
            return;
        v.push_back(root->val);
        func(root->left,v);
        func(root->right,v);
    }

    // 颜色标记法
    vector<int> preorderTraversal(TreeNode* root) {
        int white = 0, gray = 1;
        vector<int> v;
        stack<pair<int,TreeNode*>> s;
        s.push(pair<int,TreeNode*>(white,root));
        while (!s.empty())
        {
            int color = s.top().first;
            TreeNode *n = s.top().second;
            s.pop();// !!!

            if (n == NULL)// !!!
                continue;

            if (color == white)
            {
                s.push(pair<int,TreeNode*>(white,n->right));
                s.push(pair<int,TreeNode*>(white,n->left));
                s.push(pair<int,TreeNode*>(gray,n));
            }
            else
                v.push_back(n->val);
        }
        return v;
    }
};

int main()
{
    Solution s;
    // vector<int> v = {1,NULL,2,NULL,NULL,3};
    vector<int> v = {1,NULL,2,3};
    v = s.preorderTraversal(s.createFromLevelTraverse(v));
    for (auto n : v)
        printf("%d ",n);
}