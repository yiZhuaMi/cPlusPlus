//#面试题 04.02. 最小高度树

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.sortedArrayToBST());
}