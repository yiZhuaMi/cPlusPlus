#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cook, walk, eat, fish_num;
    cin>>cook>>walk>>eat>>fish_num;
    // int cook=100, walk=1, eat=3, fish_num=2;

    vector<int> dp(fish_num+1);// dp[i]:要吃i条鱼所需要的总时间
    int fish = 0;
    if (cook <= walk)// 第一次走到窗口有做好的鱼
    {
        dp[1] = walk + walk + eat;// 虽然多条鱼 但是只吃一条
        fish += walk / cook;
    }
    else// 第一次去都需要等
    {
        dp[1] = cook + walk +eat;
        fish += 1;
    }
    cout<<dp[1]<<endl;
    fish--;

    int time_goback_eat = walk + eat;
    int time_cooking = walk + eat;
    // fish += time_goback_eat / cook;// 走回去 加 吃 的时间 做好的鱼库存

    for (size_t i = 2; i <= fish_num; i++)
    {
        if (fish > 0)// 还有剩余的鱼 第i条鱼可以直接吃
        {
            dp[i] = dp[i-1] + eat;
            time_cooking += eat;
            fish += time_cooking / cook;// 吃 的时间 做好的鱼库存
            if (time_cooking >= cook)
            {
                time_cooking = time_cooking % cook;
            }
        }
        else// 还需要去拿
        {
            time_cooking += walk;
            if (cook <= time_cooking)// 走到窗口有做好的鱼
            {
                dp[i] = dp[i-1] + walk + walk + eat;// 虽然多条鱼 但是只吃一条
                fish += time_cooking / cook;
                if (time_cooking >= cook)
                {
                    time_cooking = time_cooking % cook;
                }
            }
            else// 需要等
            {
                dp[i] = dp[i-1] + cook + walk +eat;
                fish += time_cooking / cook;
                if (time_cooking >= cook)
                {
                    time_cooking = walk + time_cooking % cook;
                }
            }

        }
        fish--;// 吃掉第i条鱼

        cout<<dp[i]<<endl;
    }    
}