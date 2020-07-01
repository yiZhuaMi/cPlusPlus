// #904. 水果成篮
// 在一排树中，第 i 棵树产生 tree[i] 型的水果。
// 你可以从你选择的任何树开始，然后重复执行以下步骤：
// 把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
// 移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
// 请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。
// 你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
// 用这个程序你能收集的水果总量是多少？
// 示例 1：
// 输入：[3,3,3,1,2,1,1,2,3,3,4]
// 输出：5
// 解释：我们可以收集 [1,2,1,1,2].
// 如果我们从第一棵树或第八棵树开始，我们将只能收集到 4 个水果。

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // 指向当前待加入窗口水果
        int ind = 0;
        int res = 0;
        // 窗口内第一种／第二种水果的起始下标
        // 所以 [first_ind:sec_ind-1]都是第一种 [sec_ind:right]都是第二种
        int first_ind = 0, sec_ind = 0;
        while (ind < tree.size())
        {
            // 待加入的是区间内两种水果之一
            if (tree[ind] == tree[first_ind] || tree[ind] == tree[sec_ind])
            {
                res = max(res,ind-first_ind+1);
            }
            // 否则去掉第一种水果
            else
            {
                // 窗口内只有一种水果
                if (first_ind == sec_ind)
                    res = max(res,ind-first_ind+1);
                else
                {
                    // 找到ind左边第一个水果的起始点
                    first_ind = ind - 1;
                    while (tree[first_ind] == tree[first_ind-1])
                        first_ind--;
                }
                sec_ind = ind;
            }
            ind++;            
        }
        return res;
    }

    int totalFruit2(vector<int>& tree) {
        int K = 2;
        int i = 0, j = 0, max_res = 0;
        unordered_map<int, int> map;
        for (i = 0; i < tree.size(); i++) {
             map[tree[i]]++;
             while(map.size() > K) {
                 max_res = max(max_res,  i - j);
                 map[tree[j]]--;
                 if(map[tree[j]] == 0) map.erase(tree[j]);
                 j++;       
             }
        }
        max_res = max(max_res,  i - j);
        return max_res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,0,1,4,1,4,1,2,3};
    printf("%d\n",s.totalFruit(v));
}