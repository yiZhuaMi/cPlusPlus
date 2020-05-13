//#面试题17.12 BiNode
// 二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。
// 实现一个方法，把二叉搜索树转换为单向链表，要求值的顺序保持不变，转换操作应是原址的，
// 也就是在原始的二叉搜索树上直接修改。
// 返回转换后的单向链表的头节点。

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* createFromLevelTraverse(vector<int> list)
    {
        if (list.empty())
            return NULL;
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(list[0]);
        q.push(root);
        int ind = 1;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *n = q.front();
                
                if (ind < list.size())
                {
                    n->left = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->left != NULL)
                        q.push(n->left);
                }
                if (ind < list.size())
                {
                    n->right = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->right != NULL)
                        q.push(n->right);
                }
                q.pop();
            }
        }
        return root;
    }

    // 递归 中序遍历
    TreeNode* pre = new TreeNode(-1);// 记录中序遍历的前一个遍历的节点
    TreeNode* head = pre;// 指向最小的第一个节点

    TreeNode* convertBiNode(TreeNode* root) {
        dfs(root);
        return head->right;
    }

    void dfs(TreeNode* root)
    {
        if (root != nullptr)
        {
            dfs(root->left);// 左
            {
                root->left = nullptr;
                pre->right = root;
                pre = root;
            }
            dfs(root->right);// 右
        }
    }
};

int main()
{
    Solution s;
    s.convertBiNode(s.createFromLevelTraverse({4,2,5,1,3,NULL,6,0}));
    1;
}