//排序算法

#include <iostream>
#include <stack>
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
    // 最大的第一次沉底，次大的第二次沉底->最后是有序的
    void BubbleSort(int *a, int len) 
    {
        clock_t time_start = clock();
        for (size_t i = 0; i < len-1; i++)//i:已经排序好的个数
        {
            for (size_t j = 0; j < len-1-i; j++)//最后是排序好的不需要遍历(-i:最后有序的 -1:要取j+1)
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
    // 最前是有序的
    // 这里找到的min_ind是最右的，若左边还有与min_ind相等的，就会破坏稳定性。
    void SelectionSort(int *a, int len)
    {
        clock_t time_start = clock();
        for (size_t i = 0; i < len-1; i++)// 排序len-1次 i=排好个数 
        {
            int min_ind = i;//乱序第一个
            for (size_t j = i+1; j < len; j++)
                if (a[j] < a[min_ind])
                    min_ind = j;

            swap(a[i],a[min_ind]);
        }
        clock_t time_end = clock();
        cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) SelectionSort ";
        print_a(a,len);
    }

    // 比前面的小就与前面的‘交换’，直到比前面的大
    // (插入:每一个都要挪动 而选择排序是找到找到最小的交换到有序最后)
    void InsertionSort(int *a, int len)
    {
        clock_t time_start = clock();
        for (size_t i = 1; i < len; i++)
        {
            if (a[i-1] > a[i])// 跳过比有序的
            {
                int pre_ind = i-1;
                int cur = a[i];// 保存要插入的
                while (pre_ind >= 0 && a[pre_ind] > cur)// 比他小 他就往后挪
                {
                    a[pre_ind+1] = a[pre_ind];
                    pre_ind--;
                }
                a[pre_ind+1] = cur;// 如果没有移动的 这里不会有变化 i指向的原来的位置早已被后移替换    
            }
        }
        clock_t time_end = clock();
        cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) InsertionSort ";
        print_a(a,len);
    }

    int Quick(int *a, int left, int right)
    {
        int key = left;// key选左边一定要先从右边开始移动！！！！！！！！！！！
        while (left < right)
        {
            while (left < right && a[key] <= a[right])// 右指针指向从右往左第一个严格小于key的
            {
                right--;
            }
            while (left < right && a[left] <= a[key])// 左指针指向从左往右第一个严格大于key的
            {
                left++;
            }
            swap(a[right],a[left]);
        }
        // 左右指针(一定会)重合以后 把基准值交换到中间
        swap(a[key],a[left]);
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
        if (left >= right)
            return;
        int key = Quick(a,left,right);// 索引小于大于key的都分别在左右两边
        // print_a(a,left,right+1,key);
        QuickSort(a,left,key-1);// 所以key不用再排序了
        QuickSort(a,key+1,right);
    }

    // 快速排序 非递归
    // 递归的算法主要是在划分子区间，如果要非递归实现快排，只要使用一个栈来保存区间就可以了。
    // 一般将递归程序改成非递归首先想到的就是使用栈，因为递归本身就是一个压栈的过程。
    int partiton(int *a, int left, int right)
    {
        int key = left;
        while (left < right)
        {
            while (left < right && a[key] <= a[right])
            {
                right--;
            }
            while (left < right && a[left] <= a[key])
            {
                left++;
            }
            swap(a[right],a[left]);
        }
        swap(a[key],a[left]);
        return left;
    }

    // 特别注意区分right／r，left／l
    void QuickSortNotR(int* a, int l, int r)
    {
        stack<int> st;
        st.push(l);
        st.push(r);
        while (!st.empty())
        {
            // 后入栈的r，所以先取出来的是r
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();

            int key = partiton(a,left,right);
            // 确保区间至少有两个数
            if (key - 1 > left)
            {
                // 入栈key左边的[left,key-1]
                st.push(left);
                st.push(key - 1);
            }
            if (key + 1 < right)
            {
                // 入栈key右边的[key+1,right]
                st.push(key + 1);
                st.push(right);
            }
        }
    }

    void Merge(int *a, int l, int q, int r)
    {
        int *tmp = new int[r - l + 1]; // ！！！！！！！！！！！！！！！！！
        int i = 0, left = l, right = q+1;// 以l和q+1作为起点
        while (left <= q && right <= r)// 以q和r作为终点 逐个将小的放入tmp
            tmp[i++] = a[left] < a[right] ? a[left++] : a[right++];
        // 剩下的放入
        while (left <= q)
            tmp[i++] = a[left++];
        while (right <= r)
            tmp[i++] = a[right++];
        for (size_t j = l; j <= r; j++)// a[l:r] = tmp[0:r-l]
            a[j] = tmp[j-l];
        delete[] tmp;        
    }
    // 左右分别递归到不能拆分，开始合并，先合并左边然后合并右边。
    void MergeSort(int *a, int l, int r)
    {
        if (l >= r)
            return;
        int q = (l + r) / 2;// 用来分开数组
        MergeSort(a,l,q);// 左右分别归并排序
        MergeSort(a,q+1,r);   
        Merge(a,l,q,r);
    }
    
    // 递归构建大根堆, ind:第一个非叶子结点的下标
    void adjust(int *a, int len, int ind)
    {
        int left = 2 * ind + 1;// ind的左子节点
        int right = 2 * ind + 2;// ind的右子节点

        int max_ind = ind;// i以及两个子节点中最大的值对应下标

        // 找到三者中的max_ind
        if (left < len && a[left] > a[max_ind])
            max_ind = left;
        if (right < len && a[right] > a[max_ind])
            max_ind = right;
        if (max_ind != ind)
        {
            swap(a[ind],a[max_ind]);// 把最大的交换到父节点
            adjust(a,len,max_ind);// 现在max_ind指向较小的子节点 保证子树也是最大堆
        }
    }
    // 堆排序 建堆时间复杂度O（n）
    void HeapSort(int *a, int len)
    {
        // 构建大根堆（从右往左第一个非叶子节点 len/2-1）
        // 根节点也要调整 所以i到0
        for (int i = len / 2 - 1; i >= 0; i--)
            adjust(a,len,i);

        // 调整大根堆
        // i越来越小 后面有序的越来越多 排序len-1次
        for (int i = len - 1; i >= 1; i--)
        {
            // 将最大的元素a[0]交换到末尾
            swap(a[0],a[i]);
            // 再次对未排序的部分进行堆排序
            adjust(a,i,0);// i:长度 0:从根节点开始调整
        }
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

    int e[] = {3,6,1,4,8,2,7,9,5,10};
    time_start = clock();
    s.QuickSortNotR(e,0,len-1);
    time_end = clock();
    cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) QuickSortNotR ";
    print_a(e,len);

    int f[] = {3,6,1,4,8,2,7,9,5,10};
    time_start = clock();
    s.MergeSort(f,0,len-1);
    time_end = clock();
    cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) MergeSort ";
    print_a(f,len);

    int g[] = {3,6,1,4,8,2,7,9,5,10};
    time_start = clock();
    s.HeapSort(g,len);
    time_end = clock();
    cout<<"("<<1000*(time_end-time_start)/(double)CLOCKS_PER_SEC<<"ms) HeapSort ";
    print_a(g,len);
}