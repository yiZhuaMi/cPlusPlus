//#104 二叉树的最大深度

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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};

int main()
{
    Solution s;
    vector<int> v = {3,9,20,NULL,NULL};
    // vector<int> v = {};
}