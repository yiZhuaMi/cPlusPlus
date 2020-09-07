// #450 删除二叉搜索树中的节点
// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
// 并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* create(vector<int> list, int ind)
    {
        if (ind >= list.size() || list[ind] == NULL)
        {
            return NULL;
        }
        TreeNode *n = new TreeNode(list[ind]);
        n->left = create(list,2*ind+1);
        n->right = create(list,2*ind+2);
        return n;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        if (root->val < key)
        {
            root->right = deleteNode(root->right,key);
            return root;
        }
        if (root->val > key)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        // root 就是要删除的节点
        if (root->left == NULL)
        {
            TreeNode *tmp = root->right; 
            delete root;
            return tmp;
        }
        if (root->right == NULL)
        {
            TreeNode *tmp = root->left; 
            delete root;
            return tmp;
        }
        // 左右都不为空
        TreeNode *n = root->right;
        while (n->left != NULL)// 找到右子树中最小值(一定是个叶子结点)，与root->val交换
            n = n->left;
        root->val = n->val;// 赋最小值
        root->right = deleteNode(root->right,n->val);// 复习：一定用递归来删除找到的最小值叶子结点
        return root;
    }
};

int main()
{
   Solution s;
   vector<int> v = {1,NULL,7};
   TreeNode *root = s.create(v,0);
   s.deleteNode(root,1);
}