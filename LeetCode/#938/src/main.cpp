// #938 二叉搜索树的范围和

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

    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr)
            return 0;  
        // 判断当前root是否在要加的范围之内
        if (L <= root->val && root->val <= R)// L，R分别在根节点的左右 或者其中一个就是根节点
        {
            return root->val// 满足范围的数累加
                 + rangeSumBST(root->left,L,R)
                 + rangeSumBST(root->right,L,R);
        }
        else if (L > root->val)// 都在右边 一直递归到叶子结点 return 0
        {
            return rangeSumBST(root->right,L,R);
        }
        else// R < root->val 都在左边
        {
            return rangeSumBST(root->left,L,R);
        }
    }
};

int main()
{
   Solution s;
   vector<int> v = {10,5,15,3,7,NULL,18};
//    vector<int> v = {10,5,15};
   TreeNode *root = s.createFromLevelTraverse(v);
   printf("%d\n",s.rangeSumBST(root,7,15));
}