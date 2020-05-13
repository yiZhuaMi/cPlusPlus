//#面试题28 对称的二叉树
// 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

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
    // 层序遍历 存一半 检查另一半
    bool isSymmetric2(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            if (len % 2 == 1 && q.front() != root)// (除第一层)任意一层有奇数个节点肯定不对称
                return false;

            for (size_t i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (i * 2 < len)// 保存前一半 (用 i<len/2 的话 i=0 len=1出错)
                    v.push_back(node->val);
                else if (node->val != v[len-i-1])// 验证后一半                 
                    return false;
                    //  1
                    // / \
                    // 2  2
                    //  \   \
                    //   3   3
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            v.clear();
        }
        return true;
    }

    // 对称二叉树的中序遍历对称！
    bool isSymmetric3(TreeNode* root) {
        // 左臂入栈
        if (root == nullptr)
            return true;
        stack<TreeNode*> s;
        vector<int> v;
        while (root != nullptr)
        {
            s.push(root);
            root = root->left;
        }
        while (!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();

            v.push_back(node->val);

            // 每pop一个节点就将其右子树做左臂入栈
            node = node->right;
            while (node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
        }
        
        for (size_t i = 0; 2 * i < v.size(); i++)// 遍历前一半 (2*i<v.size() 考虑len=1 i=0)
            if (v[i] != v[v.size()-i-1])
                return false;
        return true;
    }

    // 递归
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return mirro(root->left,root->right);
    }

    bool mirro(TreeNode* left, TreeNode* right) 
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr || left->val != right->val)
            return false;
        return mirro(left->left,right->right) && mirro(right->left,left->right);// !!!!!!!!!!
    }

};

int main()
{
    Solution s;
    printf("%d\n",s.isSymmetric(s.createFromLevelTraverse({1,2,2,2,NULL,2})));
}