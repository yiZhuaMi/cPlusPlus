//#面试题40 最小的k个数

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        quickSort(arr,0,arr.size()-1);
        cout<<endl;
        vector<int> r;
        for (size_t i = 0; i < k; i++)
        {
            r.push_back(arr[i]);
        }
        return r;
    }

    void quickSort(vector<int>& arr, int left, int right)
    {
        if (left < right)
        {
            int key = partition(arr,left,right);
            quickSort(arr,left,key-1);
            quickSort(arr,key+1,right);
        }
        
    }

    int partition(vector<int>& arr, int left, int right)
    {
        int key = left;
        while (left < right)
        {
            while (left < right && arr[right] >= arr[key])
            {
                right--;
            }
            while (left < right && arr[left] <= arr[key])
            {
                left++;
            }
            swap(arr[left],arr[right]);
        }
        swap(arr[key],arr[left]);
        return left;
    }

    void swap(int &left, int &right)
    {
        int tmp = left;
        left = right;
        right = tmp;
    }

};

int main()
{
    Solution s;
    vector<int> list = {3,2,1};
    vector<int> r = s.getLeastNumbers(list,2);
    for(auto n: r)
        printf("[%d]",n);
}