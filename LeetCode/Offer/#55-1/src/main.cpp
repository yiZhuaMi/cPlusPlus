//#面试题55-1 二叉树的深度

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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + (left > right ? left : right);
    }
    // 层序遍历
    int maxDepth2(TreeNode* root) {
        if(root == NULL)
            return 0;
        int num = 0;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();// size()会变
            for(int i = 0;i < n;++i){
                TreeNode *cur = que.front();
                // 队头节点若有叶子节点就都入队 再弹出队头
                if(cur->left != NULL)
                    que.push(cur->left);
                if(cur->right != NULL)
                    que.push(cur->right);
                que.pop();
            }
            num++;
        }
        return num;
    }
};

TreeNode* createBinTree(vector<int> list, int ind)
{
    if (ind > list.size() - 1)
        return NULL;
    
    TreeNode* root = new TreeNode(list[ind]);

    root->left = (2*ind+1 < list.size() - 1) ? createBinTree(list, 2*ind+1) : NULL;
    root->right = (2*ind+2 < list.size() - 1) ? createBinTree(list, 2*ind+2) : NULL;
    
    return root;
}

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

int main()
{

    vector<int> list = {0,2,4,1,NULL,3,-1,5,1,NULL,6,NULL,8};
    // vector<int> list = {3,9,20,NULL,NULL,15,7};
    // TreeNode* root = createBinTree(list, 0);
    TreeNode* root = createFromLevelTraverse(list);
    
    Solution s;
    printf("%d\n",s.maxDepth(root));
}