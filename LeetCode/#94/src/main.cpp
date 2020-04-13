//#94 二叉树的中序遍历

#include <iostream>
#include <vector>
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
    TreeNode* create(vector<int> list, int ind)
    {
        if (ind >= list.size() || list[ind] == 0)
            return NULL;
        TreeNode *n = new TreeNode(list[ind]);// v中的NULL转换为0 这里会变成叶子结点0
        n->left = create(list,2*ind+1);
        n->right = create(list,2*ind+2);
        return n;
    }

    // 递归
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> v;
        dfs(v,root);
        return v;
    }

    void dfs(vector<int>& v, TreeNode* root)
    {
        if (root == NULL)
            return;
        dfs(v,root->left);
        v.push_back(root->val);
        dfs(v,root->right);
    }

// 颜色标记法
// 兼具栈迭代方法的高效，又像递归方法一样简洁易懂，更重要的是，
// 这种方法对于前序、中序、后序遍历，能够写出完全一致的代码。
// 1使用颜色标记节点的状态，新节点为白色，已访问的节点为灰色。
// 2如果遇到的节点为白色，则将其标记为灰色，然后将其右子节点、自身、左子节点依次入栈。
// 3如果遇到的节点为灰色，则将节点的值输出。
    vector<int> inorderTraversal(TreeNode* root) {
        int white = 0, gray = 1;
        vector<int> v;
        stack<pair<int,TreeNode*>> s;
        s.push(pair<int,TreeNode*>(white,root));
        while (!s.empty())
        {
            int color = s.top().first;
            TreeNode *n = s.top().second;
            s.pop();
            if (n == NULL)
                continue;
                
            if (color == white)// 新节点 则入依次栈
            {
                s.push(pair<int,TreeNode*>(white,n->right));// 中序遍历先进右边    
                s.push(pair<int,TreeNode*>(gray,n));    
                s.push(pair<int,TreeNode*>(white,n->left));    
            }
            else// 老节点则输出
                v.push_back(n->val);                
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,NULL,2,NULL,NULL,3};
    v = s.inorderTraversal(s.create(v,0));
    for (auto n : v)
        printf("%d ",n);
}