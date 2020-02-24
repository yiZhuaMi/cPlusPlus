#include "List.h"

List::List()
{
    pHead = new Node(0);
    // pHead->val = 0;
    // pHead->next = NULL;
    length = 0;
}

List::~List()//删头结点及以后
{
    clearList();
    delete pHead;//释放头结点指向的内存
    pHead = NULL;
}

void List::clearList()//删头结点以后
{
    Node *current_node = pHead->next;
    while (current_node != NULL)
    {
        Node *temp = current_node->next;
        delete current_node;//释放current_node指向的内存
        current_node = temp;
    }
    pHead->next = NULL;
    length = 0;
}

int List::getLength()
{
    return length;
}

bool List::empty()
{
    return !length;
}
//ind=0:插在头结点后 ind=length:插在最后一个节点后
bool List::insertNode(int ind, Node *pNode)
{
    if (ind < 0 || ind >length)
        return false;
    
    Node *p = pHead;
    //后移
    while (ind > 0)
    {
        if(p->next == NULL)
            return false;
        else
            p = p->next;
        ind--;
    }
    //插
    if(p->next != NULL)
    {
        pNode->next = p->next;
        p->next = pNode;
    }
    else//插在最后一个之后
    {
        p->next = pNode;
        pNode->next = NULL;
    }
    length++;
    return true;
}

bool List::insertNodeAtHead(Node *pNode)
{
    insertNode(0,pNode);
}

bool List::insertNodeAtTail(Node *pNode)
{
    insertNode(length,pNode);
}

//ind=1:删第一个 ind=length:删最后一个
bool List::deleteNodeByInd(int ind)
{
    if (ind < 1 || ind >length)
        return false;
    Node *p = pHead;
    while (ind > 1)//删第一个不需要后移
    {
        p = p->next;
        ind--;
    }
    Node *tmp = p->next;
    p->next = p->next->next;//可能为NULL
    delete tmp;
    length--;
    return true;
}

bool List::deleteNodeByVal(int val)
{
    if (length == 0)
        return false;
    Node *p = pHead;
    while (p->next != NULL)
    {
        if (p->next->val == val)
        {
            Node *tmp = p->next;
            p->next = p->next->next;//可能为NULL
            delete tmp;
            length--;
            return true;
        }
        p = p->next;
    }
    return false;
}
//传指针 传的是指针的拷贝 都指向同一个地址 都可改变这个地址中的值
//但修改形参指针的值(地址) 实参指针的值(地址)不变
//想修改指针本身，即指针的值，就得传指针的指针，或者传引用
bool List::getPreNode(Node *pNode, Node *pPreNode)
{
    if (length <= 1)
        return false;
    Node *p = pHead;
    p = p->next;//指向第一个
    // if (pNode == p)//为什么比较指针值不行？因为pNode本来的值就和第一个节点不一样
    if (p->val == pNode->val)
        return false;
    else
    {
        while (p->next != NULL && p->next->val != pNode->val)
            p = p->next;
        if (p->next == NULL)
            return false;
        // pPreNode = p;// × 意图改变指针的指向 实际上只会改变形参指针的指向
        // pPreNode->val = p->val;// √ 修改值
        *pPreNode = *p;// √ 修改值
        return true;
    }
}
//找pNode中的值对应的节点的下一个节点
bool List::getNextNode(Node *pNode, Node *pNextNode)
{
    if (length <= 1)
        return false;
    Node *p = pHead;
    p = p->next;//指向第一个
    while (p->val != pNode->val && p->next != NULL)
        p = p->next;
    if (p->next == NULL)
        return false;
    *pNextNode = *p->next;
    return true;
}

void List::printList()
{
    Node *p = pHead;
    printf("[head]->");
    if (length)
    {
        for (size_t i = 0; i < length; i++)
        {
            p = p->next;
            printf("[%d]->",p->val);
        }
    }
    printf("NULL\n");
}

void List::printNode(Node *node)
{

    printf("[%d]\n",node->val);
}