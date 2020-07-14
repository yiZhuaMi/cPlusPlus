// #110 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。
// 本题中，一棵高度平衡二叉树定义为：
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

#include <iostream>
#include <vector>
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (abs(depth(root->left)-depth(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(depth(root->left),depth(root->right));
    }
};

int main()
{
    Solution s;
    vector<int> v = {-10,-3,0,5,9};
    TreeNode* root = s.sortedArrayToBST(v);
    1;
}