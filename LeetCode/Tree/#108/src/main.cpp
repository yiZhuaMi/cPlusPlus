//#108 将有序数组转换为二叉搜索树
// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

#include <iostream>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums,0,nums.size());
    }

    TreeNode* createTree(vector<int>& nums, int start, int end)// end取不到
    {
        if (start >= end)// end取不到
            return nullptr;
        // 求中点不要用 int mid = (l + r)/2，有溢出风险，稳妥的方法是 int mid = l + (r-l)/2; 
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createTree(nums,start,mid);
        root->right = createTree(nums,mid+1,end);
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-10,-3,0,5,9};
    TreeNode* root = s.sortedArrayToBST(v);
    1;
}