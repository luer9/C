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
//插入
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
/*
假设两个点已经构成哈密顿，现在加入第三个点，
由竞赛图知道，第三个点与前面两个点肯定可以构成哈密顿，然后第四个点，，，，就这样做完所有点。
*/
void Hamilton(int n)
{
    int ansi=1;
    ans[ansi++]=1;//第一个点加入哈密顿图序列中
    for(int i=2;i<=n;i++)//遍历尚未加入哈密顿图的点
    {
        //if(mapp[i][ans[ansi-1]]==1)    //第一种情况,直接把当前点添加到序列末尾
        if(mapp[ans[ansi-1]][i]==1)  //倒过来也可以
        {
            ans[ansi++]=i;
        }else{
            int flag=0;
            //当前序列(哈密顿图的遍历序列)从后往前找第一个满足条件的点j,使得存在<Vj,Vi>且<Vi,Vj+1>
            for(int j=ansi-2;j>0;j--)
            {
               // if(mapp[i][ans[j]]==1)
                if(mapp[ans[j]][i]==1)
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
                if(op) mapp[i][j]=1;
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