//#面试题04.10 检查子树

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 下面的代码当t2是t1的一部分但不是t1的子树这种情况（比如t1=[2,1,3]，t2=[2]）会返回false
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr || t2 == nullptr)
            return false;
        if (t1->val == t2->val)
            return checkSubTree(t1->left,t2->left) && checkSubTree(t1->right,t2->right);
        
        return checkSubTree(t1->left,t2) || checkSubTree(t1->right,t2);
    }
};

int main()
{   
    Solution s;
}