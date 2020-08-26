/*
then go to every scenic spots once and only once and finally return to the starting spot.
要求：经过所有景点一次且仅一次，最后回到原点--->哈密顿回路  路径输出
any two scenic spots have been connected by ONE road directly
任意两个景点直接被一条路连接->(竞赛图哦)
注意：竞赛图中一定存在哈密顿路径，不一定存在哈密顿回路
任务：安排旅游路线，满足游客要求 
方法：枚举所有起点，构造哈密顿路径，然后判断起点和终点是否相同
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#define Max 1002
int mapp[Max][Max];
int ans[Max],n,cnt;
int nex[Max];
//另一种写法可以改变起点
int Hamilton(int st)
{
   cnt=1;
   memset(nex,-1,sizeof(nex));
   int head=st,tail=st;
   for(int i=1;i<=n;i++)
   {
       if(i==st) continue;
       if(mapp[i][head])//直接插入
       {
           nex[i]=head;
           head=i;
       }else
       {
           //找到合适的位置插入
           int pre=head,pos=nex[head];
           while(pos!=-1&&mapp[pos][i]){
               pre=pos;
               pos=nex[pos];
           }
           //pre->i>pos
           nex[pre]=i;
           nex[i]=pos;
           if(pos==-1) tail=i;
       }
   }
   if(mapp[tail][head])
   {
       for(int i=head;~i;i=nex[i])
            ans[cnt++]=i;
       return true;
   }
   return false;
}
bool solve()
{
    for(int i=1;i<=n;i++)
        if(Hamilton(i))
            return true;
    return false;
}
int main()
{
    while(scanf("%d",&n),n){
        memset(mapp,0,sizeof(mapp));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // read(mapp[i][j]);
               scanf("%d",&mapp[i][j]);
            }
        }
        bool flag=solve();
        if(n==1){
            printf("1\n");
        }else
        {
            if(flag)
            {
                for(int i=1;i<=n;i++)
                {
                    if(i!=1) printf(" ");
                    printf("%d",ans[i]);
                }
                printf("\n");
            }else printf("-1\n");
        }
        
    }return 0;
}