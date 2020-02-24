#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    int val;
    Node(int x) : val(x), next(NULL) {}
};

class List
{
    public:
        List();
        ~List();
        void clearList();
        int getLength();
        bool empty();
        bool insertNode(int ind, Node *pNode);
        bool insertNodeAtHead(Node *pNode);
        bool insertNodeAtTail(Node *pNode);
        bool deleteNodeByInd(int ind);
        bool deleteNodeByVal(int val);
        bool getPreNode(Node *pNode, Node *pPreNode);
        bool getNextNode(Node *pNode, Node *pNextNode);
        void printList();
        void printNode(Node *node);
        
    private:
        Node* pHead;
        int length;
};