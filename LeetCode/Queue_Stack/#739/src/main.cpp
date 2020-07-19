// #739. 每日温度
// 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，
// 至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。
// 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你
// 的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
// 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // 单调栈 栈底 <= 栈顶
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> res(T.size(),0);
        for (int i = 0; i < T.size(); i++)
        {
            // 栈中所有比新值小的全部出栈，得到与新值之间的距离
            while (!s.empty() && T[i] > T[s.top()])
            {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

int main()
{
    // printf("%d\n",s.divide(INT32_MIN,-1));
}