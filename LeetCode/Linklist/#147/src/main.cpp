// #147. 对链表进行插入排序
// 对链表进行插入排序。
// 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
// 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
// 插入排序算法：
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
// 重复直到所有输入数据插入完为止。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList2(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head->next;// 待排序的节点
        ListNode *pre = head;
        ListNode *work = nullptr;
        
        while (p != nullptr)
        {
            // 跳过有序的部分
            if (p->val >= pre->val)
            {
                p = p->next;
                pre = p;
            }
            else
            {
                // 取出p节点！！！！！！！！！！！！！！！！！！！！！！！
                work = p;
                pre->next = p->next;
                p = p->next;// p先指向下一次待排序的节点！！！！！！！！！！！！！！！！！！！！！
                // 并在有序部分找位置插入
                // 插在头节点之前
                if (work->val < head->val)
                {
                    work->next = head;
                    head = work;
                }
                else
                {
                    ListNode *pi = head;
                    while (work->val > pi->next->val)
                    {
                        pi = pi->next;
                    }
                    // 此时pi < work <= pi->next
                    work->next = pi->next;
                    pi->next = work;
                }                
            }
        }   
        return head;     
    }    
    
    // 头节点前插一个节点 这样不需要特殊处理头节点
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *phead = new ListNode(-1);
        phead->next = head;
        ListNode *p = head->next, *pre = head;
        while (p != nullptr)
        {
            if (p->val > pre->val)
            {
                pre = pre->next;
                p = p->next;
            }
            else
            {
                // 删除／跳过p
                pre->next = p->next;
                ListNode *pi = phead;// 不用特殊处理头节点
                // 从头往后找
                while (p->val > pi->next->val)
                {
                    pi = pi->next;
                }
                p->next = pi->next;// 不用特殊处理头节点
                pi->next = p;
                // 恢复p指向待排序节点
                p = pre->next;  
            }
        }
        return phead->next;
    }

    void pringList(ListNode* head)
    {
        ListNode *p = head;
        while (p != NULL)
        {
            printf("%d->",p->val);
            p = p->next;
        }        
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
    s.pringList(s.insertionSortList(n1));
}