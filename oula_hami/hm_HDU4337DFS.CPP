/*
every knight has at least (N + 1) / 2 other knights as his close friends.这句话其实是保证了哈密顿回路的存在性
基于定理Dirac：当所有点相连的点的个数大于N/2时，一定可以构造出一条哈密顿回路
*/
#include <bits/stdc++.h>
#define Max 202
using namespace std;
int vis[Max],mapp[Max][Max],ans[Max];
int n,m,u,v,flag;
void dfs(int u,int cnt)
{
    if(flag) return ;
    if(cnt==n)
    {
        if(mapp[1][ans[n-1]])
        {
            for(int i=0;i<cnt-1;i++)
                cout<<ans[i]<<" ";
            cout<<ans[cnt-1]<<endl;
            flag=1;
        }
    }else
    {
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&mapp[i][u])
            {
                vis[i]=1;
                ans[cnt]=i;
                dfs(i,cnt+1);
                vis[i]=0;
            }
        }
    }   
}
int main()
{
    while(cin>>n>>m)
    {
        memset(vis,0,sizeof(vis));
        memset(mapp,0,sizeof(mapp));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            mapp[u][v]=mapp[v][u]=1;
        }
        flag=0;
        ans[0]=1;
        vis[1]=1;
        dfs(1,1);
        if(!flag) cout<<"no solution"<<endl;
    }
    return 0;
}
/*
带回溯的深搜可以过，这样就变成和经典素数环一样的了
*/