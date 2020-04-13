//#面试题32-2 从上到下打印二叉树 II

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> v;
        q.push(root);
        while (!q.empty())// 遍历层
        {
            // printf("[");
            int len = q.size();
            vector<int> vn;
            for (size_t i = 0; i < len; i++)// 遍历一层中的节点
            {
                TreeNode *n = q.front();
                // printf("%d ",n->val);
                vn.push_back(n->val);
                if (n->left != NULL)
                    q.push(n->left);
                if (n->right != NULL)
                    q.push(n->right);    
                q.pop();        
            }
            v.push_back(vn);
            // printf("]\n"); 
        }
        return v;
    }

    static TreeNode* create2(vector<int> list, int ind)
    {
        if (ind >= list.size() || list[ind] == NULL)
        {
            return NULL;
        }
        TreeNode *n = new TreeNode(list[ind]);
        n->left = create2(list,2*ind+1);
        n->right = create2(list,2*ind+2);
        return n;
    }
};

int main()
{
    Solution s;
    vector<int> list = {3,9,20,NULL,NULL,15,7};

    TreeNode* root = s.create2(list, 0);
    // s.printTree(root);
    s.levelOrder(root);
    // s.printTree(root);

}