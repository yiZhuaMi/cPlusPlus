// #958. 二叉树的完全性检验
// 给定一个二叉树，确定它是否是一个完全二叉树。
// 百度百科中对完全二叉树的定义如下：
// 若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，
// 第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含 1~ 2h 个节点。）

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // [1,2,3,5,null,7,8]失败
    bool isCompleteTree2(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (root->left == nullptr && root->right != nullptr)
            return false;
        return isCompleteTree2(root->left) && isCompleteTree2(root->right);
    }

    // 从上到下 从左至右 只要中间有一个null就返回0
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;// 记录之前是否出现过nullptr
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node == nullptr)
                {
                    flag = 1;
                    continue;
                }
                // 这一层左边有null 但是我却不为null
                else if (flag)
                    return false;   

                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

int main()
{
   Solution s;
}