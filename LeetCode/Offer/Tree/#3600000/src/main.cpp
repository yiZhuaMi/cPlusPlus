// #面试题36. 二叉搜索树与双向链表
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
// 要求不能创建任何新的节点，只能调整树中节点指针的指向。

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        dfs(root);
    }

    Node& dfs(Node* root)
    {
        if (root == nullptr)
        {
            Node n = NULL;
            return n;
        }
        
        root->left = &dfs(root->left);
        root->right = &dfs(root->right);
        
        dfs(root->left).right = root;
        dfs(root->right).left = root;

        if (root->right != nullptr)
            return dfs(root->right);
        else
            return *root;
    }
};

int main()
{

}