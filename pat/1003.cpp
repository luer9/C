#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define Max 555
using namespace std;
int n,m,s,t,u,v,c;
int dis[Max],vis[Max],mapp[Max][Max];
int teamNum[Max],roadNum[Max],maxTeamNum[Max];
/*
roadNum数组是起点到终点的最短路相同的条数
当前点的最短路径相同的条数与前一个点最短路径相同的条数有关
maxTeamNum数组是起点到终点所有最短路中最大的救援团队数量和

*/
void dijkstra(){
    maxTeamNum[s]=teamNum[s];
    roadNum[s]=1;
    memset(dis,inf,sizeof(dis));
    for(int i=0;i<n;i++)
    {
        dis[i]=mapp[s][i];
    }
    dis[s]=0;
    // vis[s]=1;
    for(int i=0;i<n;i++)
    {
        int minn=inf,k=-1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                k=j;
            }
        }
        vis[k]=1;
        for(int v=0;v<n;v++){
            if((dis[v]>dis[k]+mapp[k][v])&&!vis[v])
            {
                dis[v]=dis[k]+mapp[k][v];
                roadNum[v]=roadNum[k];
                maxTeamNum[v]=maxTeamNum[k]+teamNum[v];
            }else if((dis[v]==dis[k]+mapp[k][v])&&!vis[v]){
                roadNum[v]+=roadNum[k];
                maxTeamNum[v]=max(maxTeamNum[k]+teamNum[v],maxTeamNum[v]);
            }
        }
    }
}
void init(){
    
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        for(int j=0;j<n;j++)
            if(i==j) mapp[i][j]=0;
            else mapp[i][j]=inf;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>s>>t;
    for(int i=0;i<n;i++) cin>>teamNum[i];
    init();
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>c;
        if(mapp[u][v]>c){
            mapp[u][v]=mapp[v][u]=c;
        }
    }
    dijkstra();
    cout<<roadNum[t]<<" "<<maxTeamNum[t]<<endl;
    return 0;
}