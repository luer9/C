/*
n 代表Tom接收任务的数量
n行 n个整数  0 or 1
如果第i行中第j个整数是1 则机器可以顺利地从任务i移动到任务j,否则机器就不能顺利地从任务i移动到任务j

输出
k 代表最小启动次数
以下 2k 行 中
第一行 m代表序列中的任务数量
第二行 包含m个整数 代表m个任务的顺序
可能有多个不同的答案，任何一个都可以
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#define ll long long
#define Max 1002 
using namespace std;
int mapp[Max][Max],ans[Max];
int n;
inline void read(int& a)
{
    char c;
    while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';
    while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';
}
void Insert(int arv[],int &len,int index,int key)
{
    if(index>len) index=len;
    len++;
    for(int i=len-1;i>=0;i--)
    {
        if(i!=index&&i)
        {
            arv[i]=arv[i-1];
        }else
        {
            arv[i]=key;
            return ;
        }
    }
}
void Hamilton(int n)
{
    int ansi=1;
    ans[ansi++]=1;
    //第一种情况,直接把当前点添加到序列末尾
    for(int i=2;i<=n;i++)
    {
        if(mapp[i][ans[ansi-1]]==1)
        {
            ans[ansi++]=i;
        }else{
            int flag=0;
            //当前序列从后往前找第一个满足条件的点j,使得存在<Vj,Vi>且<Vi,Vj+1>
            for(int j=ansi-2;j>0;j--)
            {
                if(mapp[i][ans[j]]==1)
                {
                    flag=1;
                    Insert(ans,ansi,j+1,i);
                    break;
                }
            }
            //否则说明所有点都邻接自点i,则把该点直接插入到序列首段
            if(!flag)
            {
                Insert(ans,ansi,1,i);
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(mapp,0,sizeof(mapp));
        memset(ans,0,sizeof(ans));
        int op;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                // scanf("%d",&op);  //TLE
                read(op);
                if(op==1)
                mapp[j][i]=1;
            }
        }
        printf("%d\n%d\n",1,n);
        Hamilton(n);
        for(int i=1;i<=n;i++){
            printf(i==1?"%d":" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}