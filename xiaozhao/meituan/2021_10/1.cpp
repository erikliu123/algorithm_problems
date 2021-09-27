#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
某比赛已经进入了淘汰赛阶段,已知共有n名选手参与了此阶段比赛，他们的得分分别是a_1,a_2….a_n,小美作为比赛的裁判希望设定一个分数线m，
使得所有分数大于m的选手晋级，其他人淘汰。

但是为了保护粉丝脆弱的心脏，小美希望晋级和淘汰的人数均在[x,y]之间。
显然这个m有可能是不存在的，也有可能存在多个m，如果不存在，请你输出-1，如果存在多个，请你输出符合条件的最低的分数线。


输入描述:
输入第一行仅包含三个正整数n,x,y，分别表示参赛的人数和晋级淘汰人数区间。(1<=n<=50000,1<=x,y<=n)
输入第二行包含n个整数，中间用空格隔开，表示从1号选手到n号选手的成绩。(1<=|a_i|<=1000)
*/
int main(){
    //晋级的人越多越好
    int n,x,y;
    vector<int> score;
    cin>>n>>x>>y;
    if(2*y < n)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin>>tmp;
        score.push_back(tmp);
    }
    sort(score.begin(), score.end(), greater<int>());

    //大于m的才能晋级
    int ans = -1;
    int jinji = 0;
    for(int i=0; i<n; i++)//<=y
    {
        jinji = i;
        int eliminate = n - i;//以score[i]为分数线，被排除的人个数
       
        for(int j = i-1; j >=0 ; j--)
        {
            if(score[j] == score[i])
            {
                jinji--;
                eliminate++;
            }
        }
        if(jinji>=x && jinji<=y && eliminate>=x && eliminate <=y)
        {
             ans = score[i];//设置m
        }

        if(jinji > y)
        {
            break;
        }

    }
    cout<<ans<<endl;

    
    return 0;
}