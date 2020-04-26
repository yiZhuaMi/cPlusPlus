#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // int man = 3,gift = 10,redbag = 5,new_gift = 8;
    int man,gift,redbag,new_gift;
    cin>>man>>gift>>redbag>>new_gift;
    if (man <= gift)
    {
        if (gift % man == 0)// 可以平分
        {
            cout<<0<<endl;
        }
        else
        {
            // 再买还是送人走
            int best_gitf_num = (gift / man + 1) * man;
            int queshao = best_gitf_num - gift;
            int mailiwu = queshao * new_gift;

            // int best_man = (gift / man) * man;
            int best_man = man;
            while (gift % best_man != 0)
            {
                best_man--;
            }
            int duoyu = man - best_man;
            int fahongbao = duoyu * redbag;

            cout<<min(mailiwu,fahongbao)<<endl;
        }
        
        
    }
    else// 礼物不够
    {
        if (redbag == new_gift)
        {
            cout<<(man-gift)*redbag<<endl;
        }
        else
        {
            cout<<(man-gift)*min(redbag,new_gift)<<endl;
        }
        
    }
    
    
    
}