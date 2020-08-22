//#面试题34 二叉树中和为某一值的路径
// 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
// 从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

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
    void printList(vector<int> v)
    {
        for (auto a : v)
            printf("%d ",a);
        printf("\n");
    }

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

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return ans;
    }

    void dfs(TreeNode* root, int sum)
    {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        sum -= root->val;// 不能排除有负值的情况，所以小于0也继续。
        if (root->left == nullptr && root->right == nullptr && sum == 0)// 叶子结点 找到一组解
        {
            ans.push_back(path);
            // 不能return 否则path不能回溯
        }
        // 如果是叶子结点会直接return
        dfs(root->left,sum);
        dfs(root->right,sum);
        // 当把一个节点的左右子树都检查完才会pop这个结点
        path.pop_back();// 回溯！！！ 一直递归到叶子结点才会第一次pop 自底向上pop
        // num是拷贝的，无需回溯
    }
};

int main()
{
    Solution s;
        //       5
        //      / \
        //     4   8
        //    /   / \
        //   11  13  4
        //  /  \    / \
        // 7    2  5   1
    vector<vector<int>> v = s.pathSum(s.createFromLevelTraverse({5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1}),22);
    for (auto c : v)
    {
        printf("[");
        for (auto a : c)
            printf("%d ",a);
        printf("]\n");
    }
}