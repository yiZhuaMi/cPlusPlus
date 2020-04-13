// #1302 层数最深叶子节点的和

#include <iostream>
#include <vector>
#include <queue>
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

    // 广度优先BFS 层序遍历
    int deepestLeavesSum2(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty())
        {
            int len = q.size();
            sum = 0;
            for (size_t i = 0; i < len; i++)// 遍历一层中的所有节点
            {
                TreeNode *n = q.front();
                
                if (n->left != nullptr)
                    q.push(n->left);
                if (n->right != nullptr)
                    q.push(n->right);

                sum += n->val;// 对当前层求和
                q.pop();
            }
        }
        return sum;
    }

    int maxDepth = -1;
    int sum = 0;
    
    // 深度优先DFS 递归
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return sum; 
    }

    void dfs(TreeNode* root, int dep)
    {
        if (root == nullptr)
            return;
        if (dep > maxDepth)// 突破深度 sum归零重新累加
        {
            maxDepth = dep;
            sum = root->val;
        }
        else if (dep == maxDepth)// 累加最深层
            sum += root->val;

        dfs(root->left,dep+1);// 递归子树 深度加1    
        dfs(root->right,dep+1);        
    }

};

int main()
{
   Solution s;
   vector<int> v = {1,2,3,4,5,NULL,6,7,NULL,NULL,NULL,NULL,8};
   TreeNode *root = s.createFromLevelTraverse(v);
   cout<<s.deepestLeavesSum(root);
}