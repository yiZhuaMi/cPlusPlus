#include <iostream>
#include <cstring>
using namespace std;

// 实现string
class String
{
public:
    String(const char* str = nullptr);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String& operator+=(const String& other);
    String operator+(const String& other) const;    
    char& operator[](int ind) const;
    bool operator==(const String& other) const;

    int length() const;
    const char* c_str() const;// 既不能修改this，也不能将返回值作为左值

private:
    char* _str;
    int _len;    
};

String::String(const char* str)
{
    if (str == nullptr)
    {
        _len = 0;
        _str = new char[1];
        _str[0] = '\0';
    }
    else
    {
        _len = strlen(str);// strlen不包括'\0'
        _str = new char[_len + 1];
        strcpy(_str,str);
    }
}

String::String(const String& other)
{
    if (&other != this)
    {
        _len = other._len;
        _str = new char[_len + 1];
        strcpy(_str,other._str);
    }
}

String::~String()
{
    delete _str;
}

String& String::operator=(const String& other)
{
    if (&other != this)
    {
        delete[] _str;// delete nullptr是可以的
        _len = other._len;
        _str = new char[_len + 1];
        strcpy(_str,other._str);
    }
    return *this;
}

String String::operator+(const String& other) const
{
    String tmp;
    tmp._len = _len + other._len;
    tmp._str = new char[tmp._len + 1];
    // 重点：先拷贝旧的，再连接新的
    strcpy(tmp._str,_str);
    strcat(tmp._str,other._str);
    return tmp;
}

String& String::operator+=(const String& other)
{
    _len += other._len;
    char* new_str = new char[_len + 1];
    // 重点：先拷贝旧的，再连接新的
    strcpy(new_str,_str);
    strcat(new_str,other._str);
    delete _str;
    _str = new_str;
    return *this;
}

char& String::operator[](int ind) const
{
    if (ind >= _len)
        return _str[_len];// 返回'\0'
    else
        return _str[ind];
}

bool String::operator==(const String& other) const
{
    if (_len != other._len)
        return false;
    return !strcmp(_str,other._str);// 相等则返回0
}

int String::length() const
{
    return _len;
}

const char* String::c_str() const
{
    return _str;
}