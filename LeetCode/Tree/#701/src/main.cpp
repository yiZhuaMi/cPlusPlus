// #701 二叉搜索树中的插入操作
// 给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 
// 保证原始二叉搜索树中不存在新值。
// 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

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

// 时间复杂度：O(H)，其中H 指的是树的高度。平均情况下O(logN)，最坏的情况下O(N)。
// 空间复杂度：平均情况下O(H)。最坏的情况下是O(N)，是在递归过程中堆栈使用的空间。
// 大于根往右，小于往左，最后一定是作为一个新叶子结点
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);
        if (root->val < val)// 大于跟节点
        {
            root->right = insertIntoBST(root->right,val);
        }
        else// 保证原始二叉搜索树中不存在新值 -> 不会相等
        {
            root->left = insertIntoBST(root->left,val);
        }
        return root;
    }
};

int main()
{
   Solution s;
   vector<int> v = {4,2,7,1,3};
   TreeNode *root = s.create(v,0);
   s.insertIntoBST(root,5);
}