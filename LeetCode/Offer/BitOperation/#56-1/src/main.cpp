//#面试题56-1 数组中数字出现的次数
// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
// 异或操作的定义：如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为0。
// 因此
// n^0 = n;
// n^n = 0;
// n^n^m = n^(n^m) 满足交换律
    vector<int> singleNumbers(vector<int>& nums) {
        int s = 0;
        vector<int> v(2,0);
        for (auto n : nums)// 全部异或最后的结果就等于不同的两个数的异或结果
            s ^= n;
        // 这个number的二进制数字必然包含一个1,不然就等于0了，而这两个数不相等，所以是不能为0的
        int pos = s & -s;// 因此找到number最右边第一个1的位置 并且将其他位变为0？？
        //1  0001  第一组
        //2  0010  第二组
        //1  0001  第一组
        //3  0011  第二组
        //2  0010  第二组
        //5  0101  第一组
        //第一组 1 1 5  第二组 2 3 2 这样我们就将2个只有一个的数 分到了2个数组里了
        for (auto n : nums)
            if (n & pos)
                v[0] ^= n;// 相同的组分到同一组，异或后变0，最后只剩下要找的数之一
            else
                v[1] ^= n;// 要找的不同的两个数在pos位置上肯定一个1一个0，应为他俩异或的结果在这个位置上==1，只有1^0=1.
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,1,3,2,5};
    for (auto c : s.singleNumbers(v))
        printf("%d ",c);
}