//二叉树练习

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{   
    BinaryTree<int> *tree = new BinaryTree<int>(-1);
    
    // BinaryTreeNode<int> *node = new BinaryTreeNode<int>();
    // tree->CreateBinTree(node);

    vector<int> list = {3,9,20,NULL,NULL,15,7};
    BinaryTreeNode<int>* root = tree->createBinTree(list, 0);
    tree->PreTraversal(root);

    return 0;
}