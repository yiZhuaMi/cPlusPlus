// #654 最大二叉树
// 给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
// 二叉树的根是数组中的最大元素。
// 左子树是通过数组中最大值左边部分构造出的最大二叉树。
// 右子树是通过数组中最大值右边部分构造出的最大二叉树。
// 通过给定的数组构建最大二叉树，并且输出这个树的根节点。

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums,0,nums.size());
    }

    TreeNode* constructTree(vector<int>& nums, int left, int right) {
        if (left >= right)
            return nullptr;

        int max_ind = left;
        for (size_t i = left; i < right; i++)
            if (nums[i] > nums[max_ind])
                max_ind = i;

        TreeNode *root = new TreeNode(nums[max_ind]);
        root->left = constructTree(nums,left,max_ind);
        root->right = constructTree(nums,max_ind+1,right);

        return root;
    }

};

int main()
{
   Solution s;
   vector<int> v = {3,2,1,6,0,5};
   TreeNode *t = s.constructMaximumBinaryTree(v);
   1;
}