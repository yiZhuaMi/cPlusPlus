//#124 二叉树中的最大路径和
// 给定一个非空二叉树，返回其最大路径和。
// 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

#include <iostream>
#include <vector>
#include <queue>
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
    // 层序遍历建树
    TreeNode* createFromLevelTraverse(vector<int> list)
    {
        if (list.empty())
        {
            return nullptr;
        }
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(list[0]);
        q.push(root);
        int ind = 1;
        while (!q.empty())
        {
            int len = q.size();
            for (size_t i = 0; i < len; i++)
            {
                TreeNode *n = q.front();
                if (ind < list.size())
                {
                    n->left = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->left != nullptr)
                        q.push(n->left);
                }
                if (ind < list.size())
                {
                    n->right = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->right != nullptr)
                        q.push(n->right);
                }
                q.pop();
            }
        }
        return root;
    }

    int maxSum = INT32_MIN;
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        dfs(root);
        return maxSum;
    }

    // 以每一个根节点为中间节点，计算左中右路径的和，以更新maxSum
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left_max = max(0,dfs(root->left));
        int right_max = max(0,dfs(root->right));
        maxSum = max(maxSum,root->val + left_max + right_max);// 更新真正的返回值
        // 返回经过root的单边最大分支给上游
        return root->val + max(left_max, right_max);// 返回以当前root为左中右的中间节点的最大路径和
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.maxPathSum(s.createFromLevelTraverse({-10,9,20,NULL,NULL,15,7})));
}