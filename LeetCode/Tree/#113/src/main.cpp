// #113 路径总和 II
// 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
// 说明: 叶子节点是指没有子节点的节点。
// 示例:
// 给定如下二叉树，以及目标和 sum = 22，

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// 返回:

// [
//    [5,4,11,2],
//    [5,8,4,5]
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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> line;
        dfs(root,sum,line);
        return res;
    }

    void dfs(TreeNode* root, int sum, vector<int>& line)
    {
        if (root == nullptr)
            return;
        
        sum -= root->val;
        line.push_back(root->val);
        if (sum == 0 && root->left == nullptr && root->right == nullptr)
        {
            res.push_back(line);
        }
        
        dfs(root->left,sum,line);
        dfs(root->right,sum,line);

        line.pop_back();
    }
};

int main()
{
    Solution s;
    vector<int> v = {-10,-3,0,5,9};
}