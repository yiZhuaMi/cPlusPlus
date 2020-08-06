#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
    string str, line;
    vector<string> text;
    while (cin>>str)
    {
        line += str;
        if (cin.get() == '\n')
        {
            text.push_back(line);
            line.clear();
        }
    }
    for (auto st : text)
        cout<<st<<endl;
}