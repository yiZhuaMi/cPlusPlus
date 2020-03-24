#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode() : left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *l = NULL, BinaryTreeNode<T> *r = NULL)
                   : data(x), left(l), right(r) {}
};

template <typename T>
class BinaryTree
{
    public:
        //构造与析构
        BinaryTree() : root(NULL) {}
        BinaryTree(T value) : RefValue(value), root(NULL) {}
        ~BinaryTree() {Destroy(root);}
        //创建
        void CreateBinTree(BinaryTreeNode<T> *&BT);
        BinaryTreeNode<T>* createBinTree(vector<int> list, int ind);
        //销毁
        void Destroy(BinaryTreeNode<T> *&subTree);
        //遍历
        void PreTraversal(BinaryTreeNode<T> *root);//先序

    private:
        BinaryTreeNode<T> *root;
        T RefValue;
};

template <typename T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T> *&subTree)
{
    if (subTree != NULL)
    {
        Destroy(subTree->left);
        Destroy(subTree->right);
        delete subTree;
        subTree = NULL;
    }
    
}

template <typename T>
void BinaryTree<T>::CreateBinTree(BinaryTreeNode<T> *&BT)
{
    stack<BinaryTreeNode<T>*> s;
    BT = NULL;
    BinaryTreeNode<T> *p, *t;
    int k;// k=1:左 k=2:右
    T ch;
    cin>>ch;
    while (ch != RefValue)
    {
        switch (ch)
        {
        case '(':
            s.push(p);
            k = 1;
            break;
        
        case ')':
            s.pop();
            break;

        case ',':
            k = 2;
            break;

        default:
            p = new BinaryTreeNode<T>(ch);
            if (BT == NULL)
            {
                BT = p;
            }
            else if (k ==1)
            {
                t = s.top();
                t->left = p;
            }
            else if (k ==2)
            {
                t = s.top();
                t->right = p;
            }
        }
        cin>>ch;
    }
    
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::createBinTree(vector<int> list, int ind)
{
    if (ind > list.size() - 1)
        return NULL;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(list[ind]);

    root->left = (2*ind+1 < list.size() - 1) ? createBinTree(list, 2*ind+1) : NULL;
    root->right = (2*ind+2 < list.size() - 1) ? createBinTree(list, 2*ind+2) : NULL;
    
    return root;
}

template <typename T>
void BinaryTree<T>::PreTraversal(BinaryTreeNode<T> *root)
{
    if (root != NULL)
    {
        printf(" %d ",root->data);
        PreTraversal(root->left);
        PreTraversal(root->right);
    }
}
