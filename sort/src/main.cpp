//排序算法

#include <iostream>
#include <ctime>
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

class Solution {
public:

    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // 小的逐渐往前 最大的一次性到最后
    void BubbleSort(int *a, int len) 
    {
        clock_t time_start = clock();
        for (size_t i = 0; i < len-1; i++)//i:已经排序好的个数
        {
            for (size_t j = 0; j < len-1-i; j++)//最后是排序好的不需要遍历
            {
                if (a[j] > a[j+1])
                {
                    swap(a[j],a[j+1]);
                }
            }
        }
        clock_t time_end = clock();
        cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) BubbleSort ";
        print_a(a,len);
    }

    // 找到(乱序中)最小的交换到有序最后 乱序-1
    void SelectionSort(int *a, int len)
    {
        clock_t time_start = clock();
        for (size_t i = 0; i < len-1; i++)
        {
            int min_ind = i;//乱序第一个
            for (size_t j = i+1; j < len-1; j++)
                if (a[j] < a[min_ind])
                    min_ind = j;

            swap(a[i],a[min_ind]);
        }
        clock_t time_end = clock();
        cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) SelectionSort ";
        print_a(a,len);
    }
    
    // 要插的值保存下来 比自己大的都往后挪 最后插在比自己小的后面
    // (插入:每一个都要挪动 而选择排序是找到找到最小的交换到有序最后)
    void InsertionSort(int *a, int len)
    {
        clock_t time_start = clock();
        for (size_t i = 1; i < len; i++)
        {
            int pre_ind = i-1;
            int cur = a[i];
            while (pre_ind >= 0 && a[pre_ind] > cur)// 比他小 他就往后挪
            {
                a[pre_ind+1] = a[pre_ind];
                pre_ind--;
            }
            a[pre_ind+1] = cur;// 如果没有移动的 这里不会有变化 i指向的原来的位置早已被后移替换
        }
        clock_t time_end = clock();
        cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) InsertionSort ";
        print_a(a,len);
    }

    int Quick(int *a, int left, int right)
    {
        int key = left;
        while (left < right)
        {
            while (left < right && a[key] <= a[right])// 右指针指向从右往左第一个小于key的
            {
                right--;
            }
            while (left < right && a[left] <= a[key])// 左指针指向从左往右第一个大于key的
            {
                left++;
            }
            swap(a[right],a[left]);
        }
        // 左右指针(一定会)重合以后 把基准值交换到中间
        swap(a[key],a[right]);
        return left;// 返回基准值现在的索引 此时左右指针都=基准值序号 返回左右指针都行
    }
    // 快速排序之递归左右指针法
    // 左右指针分别指向左右两端，选定基准值(最左)
    // 右指针向左移动到第一个小于基准值的元素的位置
    // 左指针向右移动到第一个大于基准值的元素的位置
    // 或者左右指针重合
    // 交换左右指针所指(大于基准值往右放 小于基准值往左放)
    // 基准值与重合的位置交换
    void QuickSort(int *a, int left, int right)
    {
        if (left < right)
        {
            int key = Quick(a,left,right);
            // print_a(a,left,right+1,key);
            QuickSort(a,left,key-1);
            QuickSort(a,key+1,right);
        }
    }

    void Merge(int *a, int l, int q, int r)
    {
        int *tmp = new int[r - l + 1]; 
        int i = 0, left = l, right = q+1;
        while (left <= q && right <= r)
            tmp[i++] = a[left] < a[right] ? a[left++] : a[right++];
        while (left <= q)
            tmp[i++] = a[left++];
        while (right <= r)
            tmp[i++] = a[right++];
        for (size_t j = 0; i < r-l+1; j++)
            a[i] = tmp[i];
        delete[] tmp;        
    }

    void MergeSort(int *a, int l, int r)
    {
        if (l == r)
            return;
        int q = (l + r) / 2;
        MergeSort(a,l,q);     
        MergeSort(a,q+1,r);   
        Merge(a,l,q,r);
    }
    
};

int main()
{
    int a[] = {3,6,1,4,8,2,7,9,5,10};
    int len = sizeof(a) / sizeof(a[0]);
    Solution s;
    print_a(a,len);
 
    s.BubbleSort(a,len);

    int b[] = {3,6,1,4,8,2,7,9,5,10};
    s.SelectionSort(b,len);

    int c[] = {3,6,1,4,8,2,7,9,5,10};
    s.InsertionSort(c,len);

    int d[] = {3,6,1,4,8,2,7,9,5,10};
    clock_t time_start = clock();
    s.QuickSort(d,0,len-1);
    clock_t time_end = clock();
    cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) QuickSort ";
    print_a(d,len);

    int e[] = {10,1};
    time_start = clock();
    s.MergeSort(e,0,2);
    time_end = clock();
    cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) MergeSort ";
    print_a(e,2);
}