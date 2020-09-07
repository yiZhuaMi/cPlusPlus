// #503 下一个更大元素 II
// 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

// 示例 1:

// 输入: [1,2,1]
// 输出: [2,-1,2]
// 解释: 第一个 1 的下一个更大的数是 2；
// 数字 2 找不到下一个更大的数； 
// 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
// 注意: 输入数组的长度不会超过 10000。

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // 单调栈
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        // 栈底到栈顶非严格递增 的元素的下标
        stack<int> s;
        // 2倍下标 相当于复制了nums 在后面
        for (int i = 2 * len -1; i >= 0; i--)
        {
            // 弹出所有比这个数小／相等的，依附于大于它的（在它后面，因为反向遍历）
            // s非空 且 新元素大于栈顶
            while (!s.empty() && nums[i % len] >= s.top())
                s.pop();

            // nums[i % len]对应的下一个最大值就是大于它的这个栈顶元素
            res[i % len] = s.empty() ? -1 : s.top();
            // 自己成为栈顶
            s.push(nums[i % len]);
        }
        return res;
    }
    
    // 与每日温度做法相同
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        // 存下标
        stack<int> st;
        vector<int> res(len,-1);
        for (int i = 0; i < 2 * len; i++)
        {
            // 递减的单调栈，大于栈顶，弹出栈顶，更新栈顶对应值
            while (!st.empty() && nums[i % len] > nums[st.top()])
            {
                res[st.top()] = nums[i % len];
                st.pop();
            }
            st.push(i % len);
        }
        return res;
    }
};

int main()
{
    // printf("%d\n",s.divide(INT32_MIN,-1));
}