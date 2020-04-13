//#面试题4-2 最小高度树

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;

        int root_ind = nums.size() / 2;
        TreeNode *n = new TreeNode(nums[root_ind]);
        
        vector<int> l_v(nums.begin(),nums.begin() + root_ind);
        n->left = sortedArrayToBST(l_v);

        vector<int> r_v(nums.end() - (nums.size() - root_ind -1),nums.end());// 后(nums.size()-root_ind-1)个元素
        n->right = sortedArrayToBST(r_v);
        
        return n;
    }

    TreeNode* creatTree(vector<int> list, int ind)
    {
        if (ind >= list.size())
            return NULL;
        TreeNode *n = new TreeNode(list[ind]);    
        n->left = creatTree(list,2*ind+1);
        n->right = creatTree(list,2*ind+2);
        return n;
    }
};

int main()
{   
    Solution s;
    vector<int> v = {-10,-3,0,5,9};// 有序
    s.sortedArrayToBST(v);// 没有打印树
}