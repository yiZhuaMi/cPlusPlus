//#面试题54 二叉搜索树的第k大节点

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        storeTree(root);
        int n = 0;
        for (map<int,int>::iterator ite = v_map.begin(); ite != v_map.end(); ite++)
        {
            if (n++ >= v_map.size()-k)
            {
                return ite->first;
            }
            
        }
        return -1;
    }

    void storeTree(TreeNode* root)
    {
        if (root == NULL)
            return;
        v_map.insert(pair<int,int>(root->val,root->val));
        storeTree(root->left);
        storeTree(root->right);
    }

    map<int,int> v_map;

    // 二叉搜索树的中序遍历是有序的！！！！！！！！！！！！！！！！！！！！！！！！！
    int kthLargest2(TreeNode* root, int k) {
        func(root,k);
        return v[v.size()-k];
    }

    void func(TreeNode* root, int k)
    {
        if (root == NULL)
            return;
        func(root->left,k);
        v.push_back(root->val);
        func(root->right,k);
    }

    vector<int> v;
};

TreeNode* createBinTree(vector<int> list, int ind)
{
    if (ind >= list.size() || list[ind] == 0)
        return NULL;
    
    TreeNode* root = new TreeNode(list[ind]);

    root->left = createBinTree(list, 2*ind+1);
    root->right = createBinTree(list, 2*ind+2);
    
    return root;
}

int main()
{

    vector<int> list = {3,1,4,NULL,2};
    TreeNode* root = createBinTree(list, 0);
    
    Solution s;
    printf("%d\n",s.kthLargest2(root,1));
}