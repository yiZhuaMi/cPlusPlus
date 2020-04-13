//#面试题68-1 二叉搜索树的最近公共祖先

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
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        // 利用搜索二叉树的特点，左子树都小于root，右子树都大于root
        if (root->val > p->val && root->val > q->val)// p,q都在左边
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if (root->val < p->val && root->val < q->val)// p,q都在右边
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else// 一个在左一个在右或者其中一个就是根节点 说明当前root就是最近公共祖先
        {
            return root;
        }
    }

    auto lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) -> TreeNode*
    {
        // 普通二叉树就一定要递归到p/q节点或者NULL 来判断在左还是右
        if (root == NULL)// 最后递归到叶子结点还没发现pq
            return NULL;
        if (root == p || root == q)
            return root;
        
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        
        if (left && right)
            return root;
        if (right)
            return right;
        if (left)
            return left;
        return NULL;
    }

    TreeNode* createTree(vector<int> list, int ind)
    {
        if (ind >= list.size())
            return NULL;
        TreeNode *n = new TreeNode(list[ind]);
        n->left = createTree(list,2*ind+1);
        n->right = createTree(list,2*ind+2);
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
};

int main()
{
    Solution s;
    vector<int> v = {6,2,8,1,4,7,9,NULL,NULL,3,5};
    TreeNode *root = s.lowestCommonAncestor2(s.createFromLevelTraverse(v),new TreeNode(2),new TreeNode(8));
}