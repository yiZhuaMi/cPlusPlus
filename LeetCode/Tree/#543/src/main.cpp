// #543 二叉树的直径
// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
// 示例 :
// 给定二叉树
//           1
//          / \
//         2   3
//        / \     
//       4   5    
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
// 注意：两结点之间的路径长度是以它们之间边的数目表示。

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
    // 类似于 #124 二叉树最大路径和（不用经过根节点）
    int max_num = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        dfs(root);
        return max_num - 1;
    }

    int dfs(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        max_num = max(max_num,l + r + 1);// 真正所求的
        return max(l,r) + 1;// 返回给上一层 左右取最大的
    }
};

int main()
{
   Solution s;
}