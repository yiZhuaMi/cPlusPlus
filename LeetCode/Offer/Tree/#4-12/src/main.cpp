//#面试题04.12 求和路径 (与Offer/#34相似)
// 给定一棵二叉树，其中每个节点都含有一个整数数值(该值或正或负)。设计一个算法，
// 打印节点数值总和等于某个给定值的所有路径的数量。
// 注意，路径【不一定非得从二叉树的根节点或叶节点开始或结束】，但是其方向必须向下
// (只能从父节点指向子节点方向)。

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
    
    vector<int> prefix;// 存放该节点的前缀和
    int count = 0;

    // 与Offer/#34的区别是不一定非得从二叉树的根节点或叶节点开始或结束
    // 前缀和:从根节点到达当前元素的路径上，之前所有元素的和。
    // 若两个节点的前缀和相差为sum，则两个节点之间的所有元素之和为sum。
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        prefix.push_back(0);// 在根节点之前添加一个0
        dfs(root,sum);
        return count;
    }

    void dfs(TreeNode* root, int target)
    {
        if (root == nullptr)
            return;
        // 更新前缀和
        int new_prefix = prefix[prefix.size()-1] + root->val;
        prefix.push_back(new_prefix);
        
        // 检查prefix中是否有前缀和的差值为target的节点 真正路径是以prefix[i]的下一个开始
        for (size_t i = 0; i < prefix.size()-1; i++)
            if (new_prefix - prefix[i] == target)
                count++;
        
        // 检查左右子树
        dfs(root->left,target);
        dfs(root->right,target);

        // 该节点以下的所有节点检查完以后 回溯 不影响其他节点
        prefix.pop_back();
    }
};

int main()
{   
    Solution s;
    printf("%d\n",s.pathSum(s.createFromLevelTraverse({5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1}),22));
}