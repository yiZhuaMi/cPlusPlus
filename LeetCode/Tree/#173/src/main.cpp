//#173 二叉搜索树迭代器
// 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
// 调用 next() 将返回二叉搜索树中的下一个最小的数。
// next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。

#include <iostream>
#include <vector>
#include <stack>
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

queue<int> q;

class BSTIterator {
public:

    void printList()
    {
        queue<int> list = q;// 拷贝初始化
        printf("q.size = %d ",q.size());
        while (!list.empty())
        {
            printf("%d ",list.front());
            list.pop();
        }
        printf("\n");
    }

    // 方法的本质上是使用左臂入栈法来中序遍历二叉搜索树，所以有序。
    // 空间复杂度O(h)
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        while (root != nullptr)
        {
            s.push(root);// 将二叉搜索树每一层最左边的节点入栈，栈顶最小。
            root = root->left;
        }        
    }
    
    /** @return the next smallest number */
    int next() {
        // 栈顶节点有两种情况：
        // 1.无右结点（所以不会有比该节点的根节点小的节点），直接返回其值。
        // 2.有右节点，先将其右子树做左臂入栈法，然后返回其值。
        TreeNode* node = s.top();
        int res = node->val;// 保存结果
        s.pop();
        node = node->right;
        while (node != nullptr)
        {
            s.push(node);
            node = node->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

int main()
{
    TreeNode *root = createFromLevelTraverse({7,3,15,NULL,NULL,9,20});
    BSTIterator* obj = new BSTIterator(root);
    // obj->printList();
    printf("%d\n",obj->next());
    printf("%d\n",obj->hasNext());
}