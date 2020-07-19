#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

bool is_triangle(int a, int b, int c)
{
    // if (a > c) swap(a,c);
    // if (b > c) swap(b,c);
    // if (a > b) swap(a,b);
    if (a + b > c && a + c > b && b + c > a)
        return true;
    else
        return false;
}

char get_highest_freq_char(const char *text)
{
    if (text[0] == '\0' || text == nullptr)
        return NULL;
    map<char,int> m;
    for (int i = 0; text[i] != '\0'; i++)
    {
        m[text[i]]++;
    }
    int max_res = 0;
    for (auto val : m)
    {
        max_res = max(max_res,val.second);
    }
    return max_res;
}

int roll_loaded_dice()
{
    int ind = rand() % 7;
    vector<int> v = {1,2,3,4,5,5,6,6};
    return v[ind];
}

void stock_price_analysis(int n, double *daily_prices, int *days_before_higher_prices)
{
    for (int i = 0; i < n; i++)
    {
        int days = 0;
        bool find = false;
        for (int j = i + 1; j < n; j++)
        {
            days++;
            if (daily_prices[j] > daily_prices[i])
            {
                days_before_higher_prices[i] = days;
                find = true;
            }
        }
        if (!find)
            days_before_higher_prices[i] = -1;
    }
    
}

int get_num_of_syllables(const char *ascii_text)
{
    int res = 0;
    for (int i = 0; ascii_text[i] != '\0'; i++)
    {
        if ((i == 0 || (ascii_text[i-1] == ' ' && ascii_text[i] != ' ')) 
           && ascii_text[i] == 'y')
        {
                continue;
        }
        else if ((ascii_text[i+1] == '\0' || (ascii_text[i] != ' ' && ascii_text[i+1] == ' ')) 
               && ascii_text[i] == 'e')
        {
                continue;
        }
        else if (ascii_text[i] == 'a' || ascii_text[i] == 'e' 
              || ascii_text[i] == 'i' || ascii_text[i] == 'o'
              || ascii_text[i] == 'u' || ascii_text[i] == 'y')
        {
            res++;
        }
    }
    return res;    
}

int main()
{
    // int num = 0;
    // cin>>num;
    // bool t = is_triangle(1,2,3);
    int count = 8;
    while (count--)
    {
        cout<<roll_loaded_dice()<<endl;
    }
    
}