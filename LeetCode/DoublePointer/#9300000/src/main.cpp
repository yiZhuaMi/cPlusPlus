// #930. 和相同的二元子数组
// 在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。
// 示例：
// 输入：A = [1,0,1,0,1], S = 2
// 输出：4
// 解释：
// 如下面黑体所示，有 4 个满足题目要求的子数组：
// [1,0,1]
// [1,0,1,0]
// [0,1,0,1]
// [1,0,1]

// 提示：
// A.length <= 30000
// 0 <= S <= A.length
// A[i] 为 0 或 1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // 错误
    int numSubarraysWithSum2(vector<int> &A, int S)
    {
        int left = 0, right = 0;
        int res = 0, sum = 0;
        while (!(left == right && left == A.size()))
        {
            if (sum < S)
            {
                // 扩张窗口
                // 还能扩张
                if (right < A.size())
                    sum += A[right++];
                else
                    break;
            }
            else if (sum > S)
            {
                // 缩小窗口
                sum -= A[left++];
            }
            else
            {
                res++;
                if (right < A.size())
                    sum += A[right++];
                else
                    sum -= A[left++];
            }
        }
        return res;
    }

    // 前缀和+hash
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        int ans = 0;
        if (A.empty())
            return 0;
        unordered_map<int, int> table;
        table[0] = 1;
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum += A[i];
            ans += table[sum - S];
            table[sum]++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 0, 1, 0, 1};
    printf("%d\n", s.numSubarraysWithSum(v, 2));
}