#include <iostream>
using namespace std;

// 实现循环队列
class CircularQueue
{
public:
    CircularQueue(int len = 10);
    CircularQueue(const CircularQueue& other);
    CircularQueue& operator=(const CircularQueue& other);
    ~CircularQueue();

    void push(int val);
    void pop();
    int size();

    bool isEmpty();
    bool isFull();

private:
    int *_a;
    int _head;
    int _rear;// 指向队尾元素的下一个，牺牲一个位置来区别队空和队满
    int _len;// 容量
};

CircularQueue::CircularQueue(int len)
{
    _a = new int[len];
    _head = 0;
    _rear = 0;
    _len = len;
}

CircularQueue::CircularQueue(const CircularQueue& other)
{
    _a = new int[other._len];
    _head = other._head;
    _rear = other._rear;
    _len = other._len;

    for (int i = _head; i !=_rear; i = (i + 1) % _len)
    {
        _a[i] = other._a[i];
    }
}

CircularQueue::~CircularQueue()
{
    if (_a != nullptr)
        delete[] _a;
    _a = nullptr;
    _head = 0;
    _rear = 0;
    _len = 0;
}

CircularQueue& CircularQueue::operator=(const CircularQueue& other)
{
    if (&other == this)
        return *this;
    if (_a != nullptr)
        delete[] _a;

    _a = new int[other._len];
    _head = other._head;
    _rear = other._rear;
    _len = other._len;

    for (int i = _head; i != _rear; i = (i + 1) % _len)
    {
        _a[i] = other._a[i];
    }
    return *this;
}

void CircularQueue::push(int val)
{
    if (!isFull())
    {
        _a[_rear] = val;
        _rear = (_rear + 1) % _len;
    }
}

void CircularQueue::pop()
{
    if (!isEmpty())
    {
        _head = (_head + 1) % _len;
    }
}

int CircularQueue::size()
{
    return (_rear - _head + _len) % _len;
}

bool CircularQueue::isEmpty()
{
    return _rear == _head;
}

// 牺牲一个位置来区别队空和队满
bool CircularQueue::isFull()
{
    return (_rear + 1) % _len == _head;
}