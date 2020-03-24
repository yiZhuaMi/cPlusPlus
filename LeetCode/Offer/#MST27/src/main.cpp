//#面试题55-1 二叉树的深度

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

TreeNode* createBinTree(vector<int> list, int ind)
{
    if (ind > list.size() - 1)
        return NULL;
    
    TreeNode* root = new TreeNode(list[ind]);

    root->left = (2*ind+1 < list.size() - 1) ? createBinTree(list, 2*ind+1) : NULL;
    root->right = (2*ind+2 < list.size() - 1) ? createBinTree(list, 2*ind+2) : NULL;
    
    return root;
}

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {

    }
};

int main()
{

    vector<int> list = {0,2,4,1,NULL,3,-1,5,1,NULL,6,NULL,8};
    // vector<int> list = {3,9,20,NULL,NULL,15,7};
    TreeNode* root = createBinTree(list, 0);
    
    Solution s;
    printf("%d\n",s.mirrorTree(root));
}