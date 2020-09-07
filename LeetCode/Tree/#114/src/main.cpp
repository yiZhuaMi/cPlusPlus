// #114 二叉树展开为链表
// 给定一个二叉树，原地将它展开为一个单链表。
// 例如，给定二叉树
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// 将其展开为：
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

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
    TreeNode* createTree(vector<int>& nums)
    {
        if (nums.empty())
            return nullptr;
        TreeNode* root = new TreeNode(nums[0]);
        queue<TreeNode*> q;
        q.push(root);
        int ind = 1;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (ind < nums.size())
                {
                    node->left = nums[ind] == NULL ? nullptr : new TreeNode(nums[ind]);
                    ind++;
                    if (node->left != nullptr)
                        q.push(node->left);
                }
                if (ind < nums.size())
                {
                    node->right = nums[ind] == NULL ? nullptr : new TreeNode(nums[ind]);
                    ind++;
                    if (node->right != nullptr)
                        q.push(node->right);
                }
            }
        }
        return root;
    }

    // 右左根的后序遍历(前序相反)
    TreeNode* last = nullptr;
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        // 复习：分别递归右左
        flatten(root->right);
        flatten(root->left);
        // 上一行递归完后 right指向原来的左子树
        root->right = last;
        root->left = nullptr;
        last = root;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-10,-3,0,5,9};
    s.flatten(s.createTree(v));
}