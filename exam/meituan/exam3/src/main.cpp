#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num, k_min;
    cin>>num>>k_min;
    int a[num];
    for (size_t i = 0; i < num; i++)
    {
        cin>>a[i];
    }
    sort(a,a+num);
    int first = a[(k_min - 1) / num];
    int second = a[(k_min % num) - 1];
    // int second = a[k_min / num -1];
    // int second = a[k_min / num];
    printf("(%d,%d)\n",first,second);
    
}