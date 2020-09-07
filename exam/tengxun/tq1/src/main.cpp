/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
            cin>>v[i];
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (i != k -1)
            cout<<v[i]<<" ";
    }
}*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> res;
    ListNode* h = new ListNode(-1);
    ListNode* p = h;
    
    for (int i = 0; i < n; i++)
    {
        p->next = new ListNode(v[i]);
        p = p->next;
    }
    p = h;
    while (--k)
    {
        p = p->next;
    }
    p->next = p->next->next;
    
    p = h;
    while (p->next != nullptr)
    {
        // cout<<p->val<<" ";
        printf("[%d]",p->next->val);
        p = p->next;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if (i != k -1)
    //         cout<<v[i]<<" ";
    // }
}