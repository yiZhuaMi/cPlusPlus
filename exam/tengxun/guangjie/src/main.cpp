
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    
    vector<int> v1;
    vector<int> v2;
    // 单调栈
    stack<int> st1;
    stack<int> st2;
    for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--)
    {
        v1.push_back(st1.size());
        v2.push_back(st2.size());

        while (!st1.empty() && st1.top() <= a[i])
            st1.pop();
        st1.push(a[i]);
        while (!st2.empty() && st2.top() <= a[j])
            st2.pop();
        st2.push(a[j]);
    }
    
    reverse(v2.begin(), v2.end());

    for (int i = 0; i < n; i++) 
        cout << v1[i] + v2[i] + 1<< " ";
    
    return 0;
}