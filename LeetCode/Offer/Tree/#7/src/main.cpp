//#面试题7 重建二叉树

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[0]);
        int i = 0;
        while (inorder[i] != root->val)// 找到根节点在中序遍历中的序号
            i++;
        // 没必要重新new vector 直接传索引
        vector<int> l_ino(inorder.begin(),inorder.begin()+i);
        vector<int> l_pre(preorder.begin()+1,preorder.begin()+1+i);
        vector<int> r_ino(inorder.begin()+1+i,inorder.end());
        vector<int> r_pre(preorder.begin()+1+i,preorder.end());
        root->left = buildTree(l_pre,l_ino);
        root->right = buildTree(r_pre,r_ino);

        return root;
    }
};

int main()
{   
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    s.buildTree(preorder,inorder);
    
}