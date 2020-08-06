#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int find_k_elem(vector<int>& v, int k, int l, int r)
{
    if (v.empty())
       return -1;
    int left = 0, right = v.size()-1;
    int key = left;
    while (left < right)
    {
        while (left < right && v[right] <= v[key])
            right--;
        while (left < right && v[left] >= v[key])
            left++;        
        swap(v[left],v[right]);
    }
    swap(v[key],v[left]);
    swap(key,left);

    if (key > k)
    {
        return find_k_elem(v,k,l,key-1);
    }
    else if (key < k)
    {
        return find_k_elem(v,k,key+1,r);
    }
    // key == k
    else
    {
        return v[key];
    }
}

int main() {
    vector<int> v = {1,4,7,3,0,2,8};
    int k = 4;
    cout<<find_k_elem(v,k-1,0,v.size()-1);
}