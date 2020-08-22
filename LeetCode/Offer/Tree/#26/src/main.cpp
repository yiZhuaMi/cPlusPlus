//#面试题26 树的子结构（检查子树）

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

    // 下面的代码当t2是t1的一部分但不是t1的子树这种情况（比如t1=[2,1,3]，t2=[2]）会返回false
    // bool isSubStructure2(TreeNode* A, TreeNode* B) {
    //     if (A == nullptr && B == nullptr)
    //         return true;
    //     if (A == nullptr || B == nullptr)
    //         return false;
    //     if (A->val == B->val)
    //         return isSubStructure2(A->left,B->left) && isSubStructure2(A->right,B->right);
        
    //     // 如果以上情况都不是的话
    //     return isSubStructure2(A->left,B) || isSubStructure2(A->right,B);
    // }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)// 约定空树不是任意一个树的子结构 // 进入dfs检查的条件
            return false;
        return dfs(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }

    bool dfs(TreeNode* A, TreeNode* B)// 检查两棵树
    {
        // 复习：这里一定先判断B！！！！！！A不空 且 B空，注意dfs第一次进来的条件是都非空
        if (B == nullptr)// 递归到B为空（一直没错）
            return true;
        if (A == nullptr)// 递归到B非空A为空
            return false;
        // 以上结束条件都不符合则继续
        return A->val == B->val && dfs(A->left,B->left) && dfs(A->right,B->right);   
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.isSubStructure(s.createFromLevelTraverse({4,2,3,4,5,6,7,8,9}),
                                   s.createFromLevelTraverse({4,8,9})));
}