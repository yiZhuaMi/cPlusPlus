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
        return max(maxDepth(root->left)+1,maxDepth(root->right)+1);
    }

    TreeNode* create(vector<int> list, int ind)
    {
        if (ind >= list.size() || list[ind] == 0)
            return NULL;
        TreeNode *n = new TreeNode(list[ind]);// v中的NULL转换为0 这里会变成叶子结点0
        n->left = create(list,2*ind+1);
        n->right = create(list,2*ind+2);
        return n;
    }
};

int main()
{
    Solution s;
    vector<int> v = {3,9,20,NULL,NULL};
    // vector<int> v = {};
    printf("%d\n",s.maxDepth(s.create(v,0)));
}