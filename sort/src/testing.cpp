//排序算法 自练习

#include <iostream>
using namespace std;

static void print_a(int *a, int len)
{
    for (size_t i = 0; i < len - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[len - 1]);
}

static void print_a(int *a, int start, int len, int key)
{
    printf("key:%d\n", key);
    for (size_t i = start; i < len - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[len - 1]);

    while ((key--) - start > 0)
    {
        printf("  ");
    }
    printf("^\n");
}

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int *a, int left, int right)
{
    int key = left;
    while (left < right)
    {
        while (left < right && a[right] >= a[key])
            right--;
        while (left < right && a[left] <= a[key])
            left++;   
         swap(a[left],a[right]);
    }
    swap(a[key],a[left]);
    return left;
}

void quickSort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int key = partition(a,left,right);
    quickSort(a,left,key-1);
    quickSort(a,key+1,right);
}

void merge(int *a, int left, int q, int right)
{
    int l = left, r = q + 1, ind = 0;
    int *temp = new int[right - left + 1];
    while (l <= q && r <= right)
    {
        temp[ind++] = a[l] <= a[r] ? a[l++] : a[r++];
    }
    while (l <= q)
    {
        temp[ind++] = a[l++];
    }
    while (r <= right)
    {
        temp[ind++] = a[r++];
    }
    for (int i = left; i <= right; i++)
    {
        a[i] = temp[i - left];
    }
    delete[] temp;
}

void mergeSort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int q = left + (right - left) / 2;
    mergeSort(a,left,q);
    mergeSort(a,q+1,right);
    merge(a,left,q,right);
}

void adjust(int *a, int len, int ind)
{
    int max_ind = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;
    if (left < len && a[left] > a[max_ind])
        max_ind = left;
    if (right < len && a[right] > a[max_ind])
        max_ind = right;
    if (max_ind != ind)
    {
        swap(a[max_ind],a[ind]);
        adjust(a,len,max_ind);
    }
}

void heapSort(int *a, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        adjust(a,len,i);
    }
    for (int i = len - 1; i > 0; i--)
    {
        swap(a[0],a[i]);
        adjust(a,i,0);
    }
}

void bbSort(int *a ,int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (a[j] > a[j+1])
                swap(a[j],a[j+1]);
        }
        
    }
    
}

void selectionSort(int *a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min_ind = i;
        for (int j = i; j < len; j++)
        {
            if (a[j] < a[min_ind])
                min_ind = j;
        }
        swap(a[i],a[min_ind]);
    }
    
}

int main()
{

    int a[] = {6, 4, 9, 8, 5, 7, 4, 3};
    int len = sizeof(a) / sizeof(a[0]);
    print_a(a, len);
    heapSort(a,len);
    print_a(a, len);
}