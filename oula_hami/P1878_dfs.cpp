#include <iostream>
#include <cstring>
#define Max 1002
using namespace std;
int mapp[Max][Max];
int vis[Max];
int deg[Max];
int n,m,u,v;
void init()
{
    memset(mapp,0,sizeof(mapp));
    memset(vis,0,sizeof(vis));
    memset(deg,0,sizeof(deg));
}
void dfs(int u)
{
    vis[u]=1;
    for(int v=1;v<=n;v++)
    {
        if(mapp[u][v]&&!vis[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        if(n==0) break;
        init();
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            mapp[u][v]=mapp[v][u]=1;
            deg[u]++,deg[v]++;
        }
        dfs(1);
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) 
            {
                flag=true;
                break;
            }
            if(deg[i]%2!=0)
            {
                flag=true;
                break;
            }
        }
        if(flag) cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;
}