//#面试题56-2 数组中数字出现的次数 II

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int,int> mp;
        for (size_t i = 0; i < nums.size(); i++)
            if (mp.find(nums[i]) != mp.end())
            {
                int n = mp[nums[i]];
                mp.erase(nums[i]);
                mp.insert(pair<int,int>(nums[i],n+1));
            }
            else// 没有记录
                mp.insert(pair<int,int>(nums[i],1));
            // 上面if else等价于mp[nums[i]]++
            // 用下标访问map中不存在的key 将创建

        auto ite = mp.cbegin();
        while (ite != mp.cend())
        {
            if (ite->second == 1)
                return ite->first;
            ite++;
        }        
        return -1;
    }

    int singleNumber2(vector<int>& nums) {
        unordered_map<int,int> map;
        for (size_t i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        for (auto ite = map.cbegin();ite != map.cend();ite++)// c开头表示const begin返回可修改的迭代器，而cbegin返回不可修改array的迭代器
            if (ite->second == 1)
                return ite->first;        
        return -1;
    }

};

int main()
{
    Solution s;
    vector<int> v = {9,1,7,9,7,9,7};
    printf("%d\n",s.singleNumber2(v));
}