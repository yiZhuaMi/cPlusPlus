// #662. 二叉树最大宽度
// 给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。
// 每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
// 示例 1:
// 输入: 
//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 
// 输出: 4
// 解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
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
            return nullptr;
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(list[0]);
        q.push(root);
        int ind = 1;
        while (!q.empty())// 每次这里都漏掉了一个取反！！！！！！！！！！！！！！！
        {
            int len = q.size();
            for (size_t i = 0; i < len; i++)
            {
                TreeNode *n = q.front();
                if (ind < list.size())
                {
                    n->left = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->left)
                        q.push(n->left);
                }
                if (ind < list.size())
                {
                    n->right = list[ind] == NULL ? nullptr : new TreeNode(list[ind]);
                    ind++;
                    if (n->right)
                        q.push(n->right);
                }
                q.pop();
            }
        }
        return root;        
    }

    // bfs
    int widthOfBinaryTree2(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode*,long>> q;// int为节点对应编号
        q.push(pair<TreeNode*,long>(root,0));
        long res = 0;
        while (!q.empty())
        {
            int len = q.size();
            // 当前层的最大最小编号
            long min_ind = INT32_MAX, max_ind = 0;
            for (int i = 0; i < len; i++)
            {
                TreeNode* node = q.front().first;
                long ind = q.front().second % INT32_MAX;// 取模！！！！！！！
                q.pop();
                
                min_ind = min(min_ind,ind);
                max_ind = max(max_ind,ind);

                if (node->left != nullptr)
                    q.push(pair<TreeNode*,long>(node->left,ind * 2 + 1));
                if (node->right != nullptr)
                    q.push(pair<TreeNode*,long>(node->right,ind * 2 + 2));                
            }
            res = max(res,max_ind - min_ind + 1);            
        }
        return res;
    }

    // dfs
    size_t res = 0;// SIZE_T ！！！！！！！！！！
    map<int,size_t> m;// 保存这一层最左侧节点的ind
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,0,0);
        return res;
    }

    void dfs(TreeNode* root, int level, size_t ind)
    {
        if (root == nullptr)
            return;
        if (m.find(level) == m.end())
            m[level] = ind;
        res = max(res,ind - m[level] + 1);
        dfs(root->left,level + 1,ind * 2 + 1);
        dfs(root->right,level + 1,ind * 2 + 2);
    }
};

int main()
{
   Solution s;
   vector<int> v = {1,3,2,5,3,NULL,9};
   s.widthOfBinaryTree(s.createFromLevelTraverse(v));
}