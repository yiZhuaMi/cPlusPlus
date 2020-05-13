// #1008 先序遍历构造二叉树
// 返回与给定先序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createTree(preorder,0,preorder.size());// end是取不到的
    }

    TreeNode* createTree(vector<int>& preorder, int start, int end) {
        if (start >= end)
            return nullptr;
        
        int split_ind;
        for (split_ind = start + 1; split_ind < end; split_ind++) 
            if (preorder[start] < preorder[split_ind])
                break;

        TreeNode* root = new TreeNode(preorder[start]);
        root->left = createTree(preorder,start+1,split_ind);
        root->right = createTree(preorder,split_ind,end);

        return root;
    }
};

int main()
{
    Solution s;
    vector<int> v = {8,5,1,7,10,12};
    TreeNode *root = s.bstFromPreorder(v);
    1;
}