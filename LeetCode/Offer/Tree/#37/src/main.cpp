//#面试题37 序列化二叉树
// 请实现两个函数，分别用来序列化和反序列化二叉树。

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "[]";
        queue<TreeNode*> q;
        q.push(root);
        vector<string> res;
        while (!q.empty())
        {
            int len = q.size();
            for (size_t i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node == nullptr)
                    res.push_back("null");
                else
                {
                    res.push_back(to_string(node->val));
                    q.push(node->left);
                    q.push(node->right);
                }                        
            }
        }
        bool conti_zero = true;
        for (int i = res.size() - 1; i >= 0; i--)
        {
            if (!conti_zero)
                break;
            if (res[i] == "null")
                res.pop_back();
            else
                conti_zero = false;
        }
        // vector -> string
        string res_str = "[";
        for (size_t i = 0; i < res.size(); i++)
        {
            res_str += res[i];
            if (i < res.size()-1)
                res_str += ",";
        }
        res_str += "]";
        return res_str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data.size() <= 2)// "[]"
            return nullptr;
        
        // string分割存为vector<string>
        data = data.substr(1,data.size());// 去掉括号
        for (size_t i = 0; i < data.size(); i++)
            if (data[i] == ',')
                data[i] = ' ';
        istringstream out(data);
        vector<string> list;
        string str;
        while (out >> str)
            list.push_back(str);

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(list[0]));
        q.push(root);
        int ind = 1;
        while (!q.empty())
        {
            int len = q.size();
            for (size_t i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (ind < list.size())
                {
                    node->left = list[ind] == "null" ? nullptr : new TreeNode(stoi(list[ind]));
                    ind++;
                    if (node->left != nullptr)
                        q.push(node->left);                    
                }
                if (ind < list.size())
                {
                    node->right = list[ind] == "null" ? nullptr : new TreeNode(stoi(list[ind]));
                    ind++;
                    if (node->right != nullptr)
                        q.push(node->right);                    
                }
            }
        }
        return root;
    }
};

int main()
{
    string data = "[1,2,3,null,null,4,5]";
    // string data = "[-1,0,1]";
    Codec codec;
    string str = codec.serialize(codec.deserialize(data));
    cout<<str;
}