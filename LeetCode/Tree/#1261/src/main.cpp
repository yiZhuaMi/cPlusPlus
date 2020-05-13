// #1261 在受污染的二叉树中查找元素
// 给出一个满足下述规则的二叉树：
// root.val == 0
// 如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 1
// 如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x + 2
// 现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 -1。

// 请你先还原二叉树，然后实现 FindElements 类：

// FindElements(TreeNode* root) 用受污染的二叉树初始化对象，你需要先把它还原。
// bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。

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

static TreeNode* createFromLevelTraverse(vector<int> list)
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

class FindElements {
public:
    FindElements(TreeNode* root) {
        tree_root = rebuild(root,0);
    }
    
    bool find(int target) {
        return exist_val(tree_root,target);
    }

    bool exist_val(TreeNode* root, int target)
    {
        if (root == nullptr)
            return false;
        if (root->val == target)
            return true;
        return exist_val(root->left,target) || exist_val(root->right,target);
    }

    TreeNode* rebuild(TreeNode* root, int val)
    {
        if (root != nullptr)
        { 
            root->val = val;
            root->left = rebuild(root->left,2 * val + 1);
            root->right = rebuild(root->right,2 * val + 2);
        }        
        return root;
    }

private:
    TreeNode* tree_root;// 若不把树还原直接用set，简单很多。
};

int main()
{
    FindElements* obj = new FindElements(createFromLevelTraverse({-1,NULL,-1,-1,NULL,-1}));
    bool param_1 = obj->find(5);
    bool param_2 = obj->find(2);
}