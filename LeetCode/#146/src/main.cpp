// #146. LRU缓存机制
// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
// 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
// 写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
// 进阶:
// 你是否可以在 O(1) 时间复杂度内完成这两种操作？
// 示例:
// LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // 返回  1
// cache.put(3, 3);    // 该操作会使得关键字 2 作废
// cache.get(2);       // 返回 -1 (未找到)
// cache.put(4, 4);    // 该操作会使得关键字 1 作废
// cache.get(1);       // 返回 -1 (未找到)
// cache.get(3);       // 返回  3
// cache.get(4);       // 返回  4

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

// struct ListNode
// {
//     int val;// 缓存的value
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {};
// };


class LRUCache {
public:
    LRUCache(int capacity):cap(capacity) {}
    
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        // 有缓存
        else
        {
            int res = m[key]->second;
            // 更新位置
            li.erase(m[key]);
            li.push_front(pair<int,int>(key,res));
            // 更新缓存位置
            m[key] = li.begin();
            return res;
        }
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end())
        {
            // 插在链表头
            li.push_front(pair<int,int>(key,value));
            // 记录位置
            m[key] = li.begin();
            // 超出容量
            if (m.size() > cap)
            {
                // 删除位置
                m.erase(li.back().first);
                // 删除缓存
                li.pop_back();
            }
        }
        // 以缓存则移动到头
        else
        {
            // 从原位置删除缓存
            li.erase(m[key]);
            // 插在链表头
            li.push_front(pair<int,int>(key,value));
            // 更新位置
            m[key] = li.begin();
        }
    }
private:
    int cap;
    // <缓存的key，缓存在list中的位置>
    map<int,list<pair<int,int>>::iterator> m;
    // <缓存的key，缓存的值>
    list<pair<int,int>> li;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{

}