//排序算法 自练习

#include <iostream>
using namespace std;

static void print_a(int *a, int len)
{
    for (size_t i = 0; i < len-1; i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[len-1]);
}

static void print_a(int *a, int start, int len, int key)
{
    printf("key:%d\n",key);
    for (size_t i = start; i < len-1; i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[len-1]);
    
    while ((key--)-start > 0)
    {
        printf("  ");
    }
    printf("^\n");
}

static void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

static void merge(int *a, int left, int q, int right)
{
    int l = left, r = q + 1;
    int *tmp = new int[right - left -1];
    int i = 0;
    while (l <= q && r <= right)
    {
        tmp[i++] = a[l] < a[r] ? a[l++] : a[r++];
    }
    while (l <= q)
        tmp[i++] = a[l++];
    while (r <= right)
        tmp[i++] = a[r++];
    for (size_t i = left; i <= right; i++)
    {
        a[i] = tmp[i-left];
    }
    delete [] tmp;
}

static void mergeSort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int q = (left + right) / 2;
    mergeSort(a,left,q);
    mergeSort(a,q+1,right);
    merge(a,left,q,right);
}


int main()
{

    int a[] = {6,4,9,8,5,7,4,3};
    int len = sizeof(a)/sizeof(a[0]);
    print_a(a,len);
    mergeSort(a,0,len-1);
    print_a(a,len);
}