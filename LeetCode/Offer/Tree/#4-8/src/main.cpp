//#面试题04.08 首个共同祖先
// 设计并实现一个算法，找出二叉树中某两个节点的第一个共同祖先。
// 不得将其他的节点存储在另外的数据结构中。
// 注意：这不一定是二叉搜索树。
// 所有节点的值都是唯一的。
// p、q 为不同节点且均存在于给定的二叉树中。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 二叉搜索树可以通过比较大小判断p／q在左还是右，而普通二叉树需要递归直到找到p／q本身，或者递归到叶子结点。
        if (root == nullptr)// 没找到p／q就会递归到叶子节点 返回空
            return nullptr;
        if (p == root || q == root)// 找到p／q就返回非空
            return root;
        // 检查子树是否有p／q
        TreeNode* left = lowestCommonAncestor(root->left,p,q);        
        TreeNode* right = lowestCommonAncestor(root->right,p,q);        
        
        // 返回非空一定是找到了p／q，都在一边的话说明返回的p或q就是【最近】祖先。
        if (left != nullptr && right != nullptr)// 一边一个
            return root;
        else if(left != nullptr)// 都在左子树
            return left;
        else// 都在右子树
            return right;
    }
};

int main()
{   
    Solution s;
}