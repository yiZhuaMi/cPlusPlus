//#面试题32-3 从上到下打印二叉树 III
// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 1;
        while (!q.empty())
        {
            int len = q.size();
            vector<int> v;
            for (size_t i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                v.push_back(node->val);
                
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            if (flag++ % 2 == 0)
                reverse(v.begin(),v.end());
            res.push_back(v);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = s.levelOrder(s.createFromLevelTraverse({3,9,20,NULL,NULL,15,7}));
    for (auto c : v)
    {
        printf("[");
        for (auto a : c)
            printf("%d ",a);
        printf("]\n");
    }
}