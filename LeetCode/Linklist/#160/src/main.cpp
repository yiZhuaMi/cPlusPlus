// #160. 相交链表
// 编写一个程序，找到两个单链表相交的起始节点。
// 如果两个链表没有交点，返回 null.
// 在返回结果后，两个链表仍须保持原有的结构。
// 可假定整个链表结构中没有循环。
// 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 若无交集 a + b = b + a = nullptr
    // 只有pa／pb不为空，就后移，这样他们可以各自指向nullptr
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pa = headA, *pb = headB;
        // 有交点 长度不同时：第一次papb切换链表不会同时==nullptr
        // 有交点 长度相同时：第一次就会同时指向交点并退出
        // 没有交点：不管长度是否相同最后都会指向nullptr
        while (pa != pb)
        {
            // 一定要让pa／pb 取到空
            // 如果 pa->next == nullptr 就取不到空 会无限循环
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;   
        }
        return pa;
    }
};

int main()
{
    Solution s;
}