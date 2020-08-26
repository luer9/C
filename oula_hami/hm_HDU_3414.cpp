/*
then go to every scenic spots once and only once and finally return to the starting spot.
Ҫ�󣺾������о���һ���ҽ�һ�Σ����ص�ԭ��--->���ܶٻ�·  ·�����
any two scenic spots have been connected by ONE road directly
������������ֱ�ӱ�һ��·����->(����ͼŶ)
ע�⣺����ͼ��һ�����ڹ��ܶ�·������һ�����ڹ��ܶٻ�·
���񣺰�������·�ߣ������ο�Ҫ�� 
������ö��������㣬������ܶ�·����Ȼ���ж������յ��Ƿ���ͬ
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
//��һ��д�����Ըı����
int Hamilton(int st)
{
   cnt=1;
   memset(nex,-1,sizeof(nex));
   int head=st,tail=st;
   for(int i=1;i<=n;i++)
   {
       if(i==st) continue;
       if(mapp[i][head])//ֱ�Ӳ���
       {
           nex[i]=head;
           head=i;
       }else
       {
           //�ҵ����ʵ�λ�ò���
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