// 237. 删除链表中的节点
// 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // node = node->next只是把node指向了node.next指向的对象，改变的只是指针node的指向，
    // 不影响实际链表的结构。例如有链表[4,5,1,9]，node = 5。node=node.next。只是把node指
    // 向了1这个节点，但是4这个节点的next依旧指向了5，所以5这个要求被删除的节点并没有被覆盖或者删除。

    // 因为无法访问前一个节点，所以无法跳过当前节点，因为前一个节点永远指向当前节点的地址，用node = node->next改变node的
    // 地址只会让node指向另一个节点,而丝毫不影响原来node指向的节点
    // 想要用node = node->next的方式除非可以访问node的前一个节点。
    void deleteNode(ListNode* head,ListNode* node) {
        // 因为无法访问前一个结点，所以可以把要删除的结点的后一个结点的值前移
        node->val = node->next->val;
        // 然后删除掉后一个结点
        node->next = node->next->next;
    }

    void deleteNode2(ListNode* head,ListNode* node) {
        *(node) = *(node->next);
    }
};

int main()
{
    Solution s;
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(1);
    ListNode *n4 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    s.deleteNode(n1,n3);
}