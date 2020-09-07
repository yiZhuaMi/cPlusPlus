// 已知一棵二叉搜索树的前序遍历序列,求二叉搜索树的中序遍历序列
// 例:
// input : 5 3 2 4 7 6
// output : 2 3 4 5 6 7
// 思路
// 1.最简单的方法是直接排序数组,因为二叉搜索树的中序遍历是有序的.
// 缺点在于排序的时间复杂度最低也是O(nlogn),并没有利用前序遍历的特点.
// 2.前序遍历的第一个节点一定是根节点,然后根据二叉搜索树左子树小于根节
// 点,右子树大于根节点的特点,将数组分为三部分,  根节点 - 左子树 - 右子树 , 
// 然后对于左右子树分别递归的采用此思想分解.      

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二叉搜索树 根据前序序列求中序序列
vector<int> func(vector<int>& nums, int l, int r)
{
    if (l > r)
        return {};
    int i = l + 1;
    while (i <= r && nums[i] < nums[l])
        i++;

    vector<int> left = func(nums,l + 1,i - 1);
    left.push_back(nums[l]);   
    vector<int> right = func(nums,i,r);
    left.insert(left.end(),right.begin(),right.end());

    return left;
}

int main()
{
    vector<int> v = {5, 3, 2, 4, 7, 6};
    v = func(v,0,v.size() - 1);
    for (auto n : v)
    {
        printf("%d ",n);
    }
}