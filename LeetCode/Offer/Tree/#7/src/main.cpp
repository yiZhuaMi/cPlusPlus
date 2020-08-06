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
        // 第一个不跳过，跳过begin+i
        vector<int> l_ino(inorder.begin(),inorder.begin()+i);
        vector<int> r_ino(inorder.begin()+1+i,inorder.end());
        // 跳过preorder第一个 后面就不会再跳过
        vector<int> l_pre(preorder.begin()+1,preorder.begin()+1+i);// 尾后迭代器
        vector<int> r_pre(preorder.begin()+1+i,preorder.end());
        root->left = buildTree(l_pre,l_ino);
        root->right = buildTree(r_pre,r_ino);

        return root;
    }

    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        // root在前序中的序号，树范围在中序中的起点，树范围在中序中的终点
        return build(preorder,inorder,0,0,inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root_ind, int start, int end)
    {
        if (start > end)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[root_ind]);
        int i = start;
        while (i < end && inorder[i] != root->val)
            i++;

        root->left = build(preorder,inorder,root_ind+1,start,i-1);
        root->right = build(preorder,inorder,root_ind+1+i-start,i+1,end);
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