#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define Max 555
using namespace std;
int n,m,s,t,u,v,c;
int dis[Max],vis[Max],mapp[Max][Max];
int teamNum[Max];
int minLen=inf;//最短路径的长度
int minlenNum=1;//最短路径的个数
int maxteamNum=0;//最大救援团队数
void init(){
    
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        for(int j=0;j<n;j++)
            if(i==j) mapp[i][j]=0;
            else mapp[i][j]=inf;
    }
}
void dfs(int cur,int cur_len,int cur_team){
    if(cur_len>minLen) return ;
    if(cur==t){
        if(cur_len<minLen)
        {
            minLen=cur_len;
            minlenNum=1;
            maxteamNum=cur_team;
        }else if(cur_len==minLen){
            minlenNum++;
            if(cur_team>maxteamNum)
            {
                maxteamNum=cur_team;
            }
        }
        return ;
    }
    vis[cur]=1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]||mapp[cur][i]==0||mapp[cur][i]==inf) continue;
        dfs(i,cur_len+mapp[cur][i],cur_team+teamNum[i]);
    }
    vis[cur]=0;
    //回溯 以便于 从其他点出发可以访问到 cur 点
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>s>>t;
    for(int i=0;i<n;i++)
    {
        cin>>teamNum[i];
    }
    init();
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>c;
        if(mapp[u][v]>c){
            mapp[u][v]=mapp[v][u]=c;
        }
    }
    dfs(s,0,teamNum[s]);
    cout<<minlenNum<<" "<<maxteamNum<<endl;
    return 0;
}