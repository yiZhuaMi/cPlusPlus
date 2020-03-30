//#面试题27 二叉树的镜像

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
    // 递归
    TreeNode* mirrorTree(TreeNode* root) {
        if (root != NULL && (root->left != NULL || root->right != NULL))
        {
            TreeNode* tmp;
            tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            mirrorTree(root->left);
            mirrorTree(root->right);
        }
        return root;
    }

    // 队列
    TreeNode* mirrorTree2(TreeNode* root) {
        if (root != NULL)
        {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode* front = q.front();
                if (front != NULL && (front->left != NULL || front->right != NULL))
                {
                    TreeNode* tmp = front->left;
                    front->left = front->right;
                    front->right = tmp;
                    q.push(front->left);
                    q.push(front->right);
                }
                q.pop();
            }
        }
        return root;
    }

    TreeNode* createBinTree(vector<int> list, int ind)
    {
        if (ind >= list.size())
            return NULL;
        
        TreeNode* root = new TreeNode(list[ind]);

        root->left = (2*ind+1 < list.size()) ? createBinTree(list, 2*ind+1) : NULL;
        root->right = (2*ind+2 < list.size()) ? createBinTree(list, 2*ind+2) : NULL;
        
        return root;
    }

    static TreeNode* create(vector<int> list, int ind)
    {
        if (ind >= list.size())
            return NULL;

        TreeNode* node = new TreeNode(list[ind]);
        node->left = create(list,2*ind+1);
        node->right = create(list,2*ind+2);
        return node;
    }
    // 层序遍历
    void printTree(TreeNode* root)
    {
        if (root == NULL)
            return;
        queue<TreeNode*> q,r;
        q.push(root);
        r.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (size_t i = 0; i < n; i++)
            {
                TreeNode* front = q.front();
                if(front->left != NULL)
                {
                    q.push(front->left);
                    r.push(front->left);
                }    

                if(front->right != NULL)
                {
                    q.push(front->right);
                    r.push(front->right);
                }    
                
                q.pop();
            }
        }

        while (!r.empty())
        {
            cout<<r.front()->val<<" ";
            r.pop();
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;
    vector<int> list = {4,2,7,1,3,NULL,9};
    // vector<int> list = {1,2,3};
    // vector<int> list = {};

    // TreeNode* root = s.createBinTree(list, 0);
    TreeNode* root = s.create(list, 0);
    s.printTree(root);
    s.mirrorTree2(root);
    s.printTree(root);

}