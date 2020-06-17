//#面试题33 二叉搜索树的后序遍历序列
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，
// 否则返回 false。假设输入的数组的任意两个数字都互不相同。

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
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder,0,postorder.size()-1);
    }

    bool verify(vector<int>& nums, int l, int r)
    {
        if (l >= r)// 递归终止 || 空树
            return true;
        int root_val = nums[r];
        // 从root开始往前找右子树：把所有连续大于root的都当作右子树区
        int right_start = r;
        while (right_start >= l && nums[right_start] >= root_val)// 没有相同的值
            right_start--;
        right_start++;// 指向root左边连续大于root的子串的第一个（如果有）（=l则左子树空 =r则右子树空）
        
        // 如果是二叉搜索树的后序遍历 此时right_start左边（如果有）的应该都小于root
        int ind = l;
        while (ind < right_start)// 左子树区都应该小于root
        {
            if (nums[ind] >= root_val)
                return false;    
            ind++;        
        }
        return verify(nums,l,right_start-1) && verify(nums,right_start,r-1);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,3,2,6,5};
    s.verifyPostorder(v);
}