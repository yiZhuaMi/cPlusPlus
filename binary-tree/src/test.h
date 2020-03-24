#include <iostream>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;

template <typename T>
struct BinTreeNode
{
    T data;                                                                                                        //结点中存储的数据
    BinTreeNode<T> *leftChild, *rightChild;                                                                        //左子树和右子树
    BinTreeNode() : leftChild(NULL), rightChild(NULL) {}                                                           //无参构造函数
    BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) : data(x), leftChild(l), rightChild(r) {} //带默认值的有参构造参数
};

//二叉树类
template <typename T>
class BinaryTree
{
public:

//==========二叉树构造与析构==========//

    //构造函数
    BinaryTree() : root(NULL) {}

    //指定结束标志的构造函数
    BinaryTree(T value) : RefValue(value), root(NULL) {}

    //析构函数
    ~BinaryTree() { Destroy(root); }

//==========二叉树的创建==========//

    //使用广义表创建二叉树，以'#'字符代表结束
    void CreateBinTree();

    //前序遍历创建二叉树(前序遍历的应用)，用#表示空结点
    void CreateBinTree_PreOrder();

    //使用先序遍历和中序遍历创建二叉树
    void CreateBinTreeBy_Pre_In(const char *pre, const char *in);
    // {
    //     int n = strlen(pre);
    //     CreateBinTreeBy_Pre_In(root, pre, in, n);
    // }

    //使用后序遍历和中序遍历创建二叉树
    void CreateBinTreeBy_Post_In(const char *post, const char *in);

//==========二叉树的遍历==========//

    //先序遍历（递归）
    void PreOrder();

    //中序遍历(递归)
    void InOrder();

    //后序遍历（递归）
    void PostOrder();

    //先序遍历(非递归)
    void PreOrder_NoRecurve();

    //中序遍历(非递归)
    void InOrder_NoRecurve();

    //后序遍历(非递归)
    void PostOrder_NoRecurve();

    //层次遍历(非递归)
    void LevelOrder();

//==========获取结点==========//

    //获取二叉树的根节点
    BinTreeNode<T> *getRoot() const
    {
        return root;
    }

    //获取current结点的父节点
    BinTreeNode<T> *Parent(BinTreeNode<T> *current);

    //获取current结点的左结点
    BinTreeNode<T> *LeftChild(BinTreeNode<T> *current)
    {
        return (current != NULL) ? current->leftChild : NULL;
    }

    //获取current结点的右结点
    BinTreeNode<T> *RightChild(BinTreeNode<T> *current)
    {
        return (current != NULL) ? current->rightChild : NULL;
    }

//==========成员函数==========//

    //销毁函数
    void Destroy();

    //拷贝二叉树(前序遍历的应用)
    BinTreeNode<T> *Copy(BinaryTree<T> &s);

    //判断两颗二叉树是否相等(前序遍历的应用)
    bool operator==(BinaryTree<T> &s);

    //计算二叉树的结点的个数(后序遍历的应用)
    int Size(BinaryTree<T> &s);

    //计算二叉树的高度（后序遍历的应用）
    int Height(BinTreeNode<T> *root);

    //判断二叉树是否为空
    bool Empty() { return (root == NULL) ? true : false; }

    //以广义表的形式输出二叉树(前序遍历的应用)
    void PrintBinTree(BinTreeNode<T> *root);

private:
    BinTreeNode<T> *root; //根节点
    T RefValue;           //数据输入停止的标志，需要一个构造函数
};

//使用广义表创建二叉树函数,这里以“字符”创建二叉树,以'#'字符代表结束
template <typename T>
void BinaryTree<T>::CreateBinTree()
{
    BinTreeNode<T> *&BT = root;
    stack<BinTreeNode<T> *> s;
    BT = NULL;
    BinTreeNode<T> *p, *t; //p用来记住当前创建的节点，t用来记住栈顶的元素
    int k;                 //k是处理左、右子树的标记
    T ch;
    cin >> ch;

    while (ch != RefValue)
    {
        switch (ch)
        {
        case '(': //对(做处理
            s.push(p);
            k = 1;
            break;

        case ')': //对)做处理
            s.pop();
            break;

        case ',': //对,做处理
            k = 2;
            break;

        default:
            p = new BinTreeNode<T>(ch); //构造一个结点
            if (BT == NULL)             //如果头节点是空
            {
                BT = p;
            }
            else if (k == 1) //链入*t的左孩子
            {
                t = s.top();
                t->leftChild = p;
            }
            else //链入*t的右孩子
            {
                t = s.top();
                t->rightChild = p;
            }
        }
        cin >> ch;
    }
}

//创建二叉树(利用已知的二叉树的前序遍历创建)用#表示空结点
template <typename T>
void BinaryTree<T>::CreateBinTree_PreOrder()
{
    BinTreeNode<T> *&BT = root;
    T item;
    if (cin >> item)
    {
        if (item != RefValue)
        {
            subTree = new BinTreeNode<T>(item); //构造结点
            if (subTree == NULL)
            {
                cout << "空间分配错误！" << endl;
                exit(1);
            }
            CreateBinTree_PreOrder(subTree->leftChild);  //递归创建左子树
            CreateBinTree_PreOrder(subTree->rightChild); //递归创建右子树
        }
        else
        {
            subTree == NULL;
        }
    }
}

//使用先序遍历和中序遍历创建二叉树
template <typename T>
void BinaryTree<T>::CreateBinTreeBy_Pre_In(const char *pre, const char *in)
{
    BinTreeNode<T> *&cur = root;
    n = strlen(pre);
    if (n <= 0)
    {
        cur = NULL;
        return;
    }
    int k = 0;
    while (pre[0] != in[k]) //再中序中找到pre[0]的值
    {
        k++;
    }
    cur = new BinTreeNode<T>(in[k]); //创建结点
    CreateBinTreeBy_Pre_In(cur->leftChild, pre + 1, in, k);
    CreateBinTreeBy_Pre_In(cur->rightChild, pre + k + 1, in + k + 1, n - k - 1);
}
//使用后序遍历和中序遍历创建二叉树
template <typename T>
void BinaryTree<T>::CreateBinTreeBy_Post_In(const char *post, const char *in)
{
    BinTreeNode<T> *&cur = root;
    n = strlen(pre);
    if (n == 0)
    {
        cur = NULL;
        return;
    }

    char r = *(post + n - 1);    //根结点值
    cur = new BinTreeNode<T>(r); //构造当前结点

    int k = 0;
    const char *p = in;
    while (*p != r)
    {
        k++;
        p++;
    }
    CreateBinTreeBy_Post_In(cur->leftChild, post, in, k);
    CreateBinTreeBy_Post_In(cur->rightChild, post + k, p + 1, n - k - 1);
}

//先序遍历(递归)
template <typename T>
void BinaryTree<T>::PreOrder()
{
    BinTreeNode<T> *&subTree = root;
    if (subTree != NULL)
    {
        cout << subTree->data << " ";
        PreOrder(subTree->leftChild);
        PreOrder(subTree->rightChild);
    }
}

//中序遍历(递归)
template <typename T>
void BinaryTree<T>::InOrder()
{
    BinTreeNode<T> *&subTree = root;
    if (subTree != NULL)
    {
        InOrder(subTree->leftChild);
        cout << subTree->data << " ";
        InOrder(subTree->rightChild);
    }
}

//后序遍历(递归)
template <typename T>
void BinaryTree<T>::PostOrder()
{
    BinTreeNode<T> *&subTree = root;
    if (subTree != NULL)
    {
        PostOrder(subTree->leftChild);
        PostOrder(subTree->rightChild);
        cout << subTree->data << " ";
    }
}

//先序遍历（非递归）
template <typename T>
void BinaryTree<T>::PreOrder_NoRecurve()
{
    BinTreeNode<T> *p = root;
    stack<BinTreeNode<T> *> S;
    BinTreeNode<T> *t;
    S.push(p);         //根节点进栈
    while (!S.empty()) //当栈不为空
    {
        t = S.top(); //p先记住栈顶元素，然后栈顶出栈
        S.pop();
        cout << t->data << " ";    //访问元素
        if (t->rightChild != NULL) //右孩子不为空，右孩子近栈
        {
            S.push(t->rightChild);
        }
        if (t->leftChild != NULL) //左孩子不为空，左孩子进栈
        {
            S.push(t->leftChild);
        }
    }
}

//中序遍历(非递归)
template <typename T>
void BinaryTree<T>::InOrder_NoRecurve()
{
    if (root == NULL)
        return;
    stack<BinTreeNode<T> *> s;
    s.push(root);
    while (!s.empty())
    {
        while (s.top()->leftChild != NULL) //将左结点依次入栈
        {
            s.push(s.top()->leftChild);
        }
        while (!s.empty())
        {
            BinTreeNode<T> *cur = s.top();
            cout << cur->data << " ";
            s.pop();
            if (cur->rightChild != NULL)
            {
                s.push(cur->rightChild);
                break;
            }
        }
    }
}

//后序遍历(非递归)
template <typename T>
void BinaryTree<T>::PostOrder_NoRecurve()
{
    BinTreeNode<T> *p = root;
    if (root == NULL)
        return;
    stack<BinTreeNode<T> *> s;
    s.push(p);
    BinTreeNode<T> *lastPop = NULL;
    while (!s.empty())
    {
        while (s.top()->leftChild != NULL)
            s.push(s.top()->leftChild);
        while (!s.empty())
        {
            //右叶子结点 || 没有右结点
            if (lastPop == s.top()->rightChild || s.top()->rightChild == NULL)
            {
                cout << s.top()->data << " ";
                lastPop = s.top();
                s.pop();
            }
            else if (s.top()->rightChild != NULL)
            {
                s.push(s.top()->rightChild);
                break;
            }
        }
    }
}

//层次遍历(非递归)
template <typename T>
void BinaryTree<T>::LevelOrder()
{
    BinTreeNode<T> *p = root;
    queue<BinTreeNode<T> *> Q;
    Q.push(p); //根节点进队
    BinTreeNode<T> *t;
    while (!Q.empty())
    {
        t = Q.front(); //t先记住队头,再将队头出队
        Q.pop();
        cout << t->data << " "; //访问队头元素的数据

        if (t->leftChild != NULL)
        {
            Q.push(t->leftChild);
        }

        if (t->rightChild != NULL)
        {
            Q.push(t->rightChild);
        }
    }
}

//从结点subTree开始，搜索结点current的父节点,找到返回父节点的地址，找不到返回NULL
template <typename T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *current)
{
    if (root == NULL || root == current)
            return NULL;
    //如果没有根节点或current结点就是root结点，就没有父节点
    subTree = root;
    if (subTree == NULL)
    {
        return NULL;
    }
    if (subTree->leftChild == current || subTree->rightChild == current) //如果找到，返回父节点subTree
    {
        return subTree;
    }
    BinTreeNode<T> *p;
    if (p = Parent(subTree->leftChild, current) != NULL) //递归在左子树中搜索
    {
        return p;
    }
    else
    {
        return Parent(subTree->rightChild, current); //递归右子树中搜索
    }
}

//二叉树的销毁
template <typename T>
void BinaryTree<T>::Destroy()
{
    if (root != NULL)
    {
        Destroy(root->leftChild);
        Destroy(root->rightChild);
        delete root;
        root = NULL;
    }
}

//复制二叉树函数，返回一个指针，给出一个以originNode为根复制的二叉树的副本
template <typename T>
BinTreeNode<T> *BinaryTree<T>::Copy(BinaryTree<T> &s)
{
    BinTreeNode<T> *originNode = s.getRoot();
    if (originNode == NULL)
    {
        return NULL;
    }
    BinTreeNode<T> *temp = new BinTreeNode<T>; //创建根结点
    temp->data = originNode->data;
    temp->leftChild = Copy(originNode->leftChild);
    temp->rightChild = Copy(originNode->rightChild);
    return temp;
}

//判断两颗二叉树是否相等
template <typename T>
bool BinaryTree<T>::operator==(BinaryTree<T> &s)
{

    BinTreeNode<T> *a = root;
    BinTreeNode<T> *b = s.getRoot();
    return (equal(this->getRoot(), ));
    
    if (a == NULL && b == NULL) //两者都为空
    {
        return true;
    }
    if (a != NULL && b != NULL && a->data == b->data && equal(a->leftChild, b->leftChild) && equal(a->rightChild, b->rightChild)) //两者都不为空，且两者的结点数据相等，且两者的左右子树的结点都相等
    {
        return true;
    }
    return false;
}

//计算二叉树以subTree为根的结点的个数
template <typename T>
int BinaryTree<T>::Size(BinaryTree<T> &s)
{
    if (s == NULL) //递归结束，空树结点个数为0
    {
        return 0;
    }
    return 1 + Size(s->leftChild) + Size(s->rightChild);
}

//计算二叉数以subTree为根的高度
template <typename T>
int BinaryTree<T>::Height(BinTreeNode<T> *s)
{
    if (s == NULL) //递归结束，空树高度为0
    {
        return 0;
    }
    int i = Height(s->leftChild);
    int j = Height(s->rightChild);
    return i < j ? j + 1 : i + 1;
}

//以广义表的形式输出二叉树
template <typename T>
void BinaryTree<T>::PrintBinTree(BinTreeNode<T> *BT)
{
    if (BT != NULL) //树为空时结束递归
    {
        cout << BT->data;
        if (BT->leftChild != NULL || BT->rightChild != NULL)
        {
            cout << '(';
            if (BT->leftChild != NULL)
            {
                PrintBinTree(BT->leftChild);
            }
            cout << ',';
            if (BT->rightChild != NULL)
            {
                PrintBinTree(BT->rightChild);
            }
            cout << ')';
        }
    }
}

int main()
{   
    BinaryTree<int> *tree = new BinaryTree<int>(-1);
    BinTreeNode<int> *node = new BinTreeNode<int>();
    tree->CreateBinTree(node);
}