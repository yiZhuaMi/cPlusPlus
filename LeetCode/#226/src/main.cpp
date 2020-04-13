//#226 翻转二叉树

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr)
            return root;
        TreeNode *tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }

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

    // 层序遍历
    void printTreePerLevel(TreeNode* root)
    {
        if (root == nullptr)
            return;
        queue<TreeNode*> q,r;
        q.push(root);
        r.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (size_t i = 0; i < n; i++)
            {
                TreeNode* front = q.front();
                if(front != nullptr && (front->left != nullptr || front->right != nullptr))// 有一个不为空就输出
                {
                    q.push(front->left);
                    r.push(front->left);
                    q.push(front->right);
                    r.push(front->right);
                }    
                q.pop();
            }
        }
        while (!r.empty())
        {
            if (r.front() != nullptr)
                cout<<r.front()->val<<" ";
            else
                cout<<"NULL ";
            r.pop();
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,NULL,3,4,5,NULL,NULL,6};
    TreeNode *root = s.createFromLevelTraverse(v);
    s.printTreePerLevel(root);
    s.printTreePerLevel(s.invertTree(root));
}