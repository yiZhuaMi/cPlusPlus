// #102. 二叉树的层序遍历
// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
// 示例：
// 二叉树：[3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其层次遍历结果：
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();  
                level.push_back(node->val);

                if (node->left == nullptr)
                    q.push(node->left);
                if (node->right == nullptr)
                    q.push(node->right);      
            }            
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {3,9,20,NULL,NULL};
    // vector<int> v = {};
    printf("%d\n",s.maxDepth(s.create(v,0)));
}