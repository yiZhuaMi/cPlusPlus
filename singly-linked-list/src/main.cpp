//单链表练习

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List *list = new List();
    for (size_t i = 0; i < 10; i++)
    {
        Node *node = new Node(i);
        list->insertNode(i,node);
    }
    
    printf("length:%d\n",list->getLength());
    printf("empty:%d\n",list->empty());
    list->printList();
    
    printf("%s\n",list->deleteNodeByInd(9) ? "delete sucsess" : "delete failed");
    list->printList();
    
    printf("%s\n",list->deleteNodeByVal(9) ? "delete sucsess" : "delete failed");
    list->printList();

    Node * n1 = new Node(11);
    list->insertNodeAtHead(n1);
    list->printList();

    Node * n2 = new Node(22);
    list->insertNodeAtTail(n2);
    list->printList();

    Node * n3 = new Node(66);
    Node * pre_n3 = new Node(-1);
    printf("%s\n",list->getPreNode(n3,pre_n3) ? "getPreNode sucsess" : "getPreNode failed");
    list->printNode(pre_n3);

    Node * n4 = new Node(55);
    Node * next_n4 = new Node(-1);
    printf("%s\n",list->getNextNode(n4,next_n4) ? "getNextNode sucsess" : "getNextNode failed");
    list->printNode(next_n4);

    list->clearList();
    list->printList();
}