// #590 N叉树的后序遍历

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // 递归
    vector<int> postorder2(Node* root) {
        vector<int> v;
        backOrder(root,v);
        return v;
    }

    void backOrder(Node* root, vector<int> &v)
    {
        if (root != nullptr)
        {
            for (size_t i = 0; i < root->children.size(); i++)
            {
                backOrder(root->children[i],v);
            }
            v.push_back(root->val);
        }
    }

    // 迭代 颜色标记法
    vector<int> postorder(Node* root) {
        if (root == nullptr)
            return {};
        int white = 0, gray = 1;
        stack<pair<int,Node*>> s;
        s.push(pair<int,Node*>(white,root));
        vector<int> v;
        while (!s.empty())
        {
            int color = s.top().first;
            Node *n = s.top().second;
            s.pop();
            if (n == nullptr)
                continue;
            
            if (color == white)
            {
                s.push(pair<int,Node*>(gray,n));
                for (auto ite = n->children.rbegin(); ite != n->children.rend(); ite++)
                {
                    s.push(pair<int,Node*>(white,*ite));
                }
            }    
            else
                v.push_back(n->val);            
        }
        return v;
    }
};

int main()
{
   Solution s;
}