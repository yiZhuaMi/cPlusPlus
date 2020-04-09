//#面试题35 复杂链表的复制

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node * p = head;
        while (p != NULL)
        {
            Node *n = new Node(p->val);
            n->next = p->next;
            p->next = n;
            p = p->next->next;
        }
        p = head;
        // 处理新节点的random指针
        while (p != NULL)
        {
            p->next->random = p->random == NULL ? NULL : p->random->next;
            p = p->next->next;
        }
        p = head;
        Node *p1 = head->next, *p2 = p1;
        while (p1 != NULL & p1->next != NULL)
        {
            // 还原
            p->next = p1->next;
            p = p->next;
            // 拆分
            p1->next = p1->next->next;
            p1 = p1->next;
        }
        p->next = NULL;
        return p2;
    }

    void printList(Node* head)
    {
        Node *p = head;
        while (p != NULL)
        {
            printf("[%d,",p->val);
            if (p->random != NULL)
                printf("%d]",p->random->val);
            else
                printf("NULL]");

            p = p->next;
        }
        printf("\n");
    }
};

int main()
{
    //leetcode中链表默认没有头结点
    Node *n1 = new Node(7);
    Node *n2 = new Node(13);
    Node *n3 = new Node(11);
    Node *n4 = new Node(10);
    Node *n5 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution s;
    s.printList(n1);
    s.printList(s.copyRandomList(n1));
}