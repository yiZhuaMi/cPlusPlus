// #1305 两棵二叉搜索树中的所有元素

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
                    n->left = list[ind] == -1 ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->left != nullptr)
                        q.push(n->left);
                }
                if (ind < list.size())
                {
                    n->right = list[ind] == -1 ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->right != nullptr)
                        q.push(n->right);
                }
                q.pop();
            }
        }
        return root;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        dfs(root1,v);
        dfs(root2,v);
        sort(v.begin(),v.end());
        return v;
    }

    void dfs(TreeNode *root, vector<int> &v)
    {
        if (root != nullptr)
        {
            v.push_back(root->val);
            dfs(root->left,v);
            dfs(root->right,v);
        }
    }
};

int main()
{
   Solution s;
   vector<int> v1 = {2,1,4};
   vector<int> v2 = {1,0,3};
   TreeNode *root1 = s.createFromLevelTraverse(v1);
   TreeNode *root2 = s.createFromLevelTraverse(v2);
   vector<int> v = s.getAllElements(root1,root2);
   for (auto c : v)
        printf("%d ",c);
}