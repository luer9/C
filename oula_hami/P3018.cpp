/*
They intend to visit every road , and every road must be visited for exact one time.
No two roads will be the same,and there is no road connecting the same town.
目标：访问每一个城镇，并且每条路(边)经过一次且路只有一条
一个大组被分成几个小组 来访问城镇 
求至少分几个组，才能实现目标
就比如：一笔画问题：需要几笔才能把所有边都画完
hint:没有一条路与某一结点相连接，小蚂蚁就会忘记这个结点

ans=欧拉路的个数+连通图中度数为奇的个数/2
why? https://blog.csdn.net/u013480600/article/details/30285541
*/
#include <bits/stdc++.h>
#define Max 100002
using namespace std;
int n,m,u,v,cnt;
int deg[Max],odd[Max],fa[Max];
int vis[Max];
vector<int> vec;//存储父节点 可以判断有多少个连通块
void init()
{
    vec.clear();
    for(int i=1;i<=n;i++) fa[i]=i;
    memset(deg,0,sizeof(deg));
    memset(odd,0,sizeof(odd));
    memset(vis,0,sizeof(vis));
}
int Find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
void mix(int x,int y)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)
    {
        fa[fx]=fy;
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        init();
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            deg[u]++,deg[v]++;
            mix(u,v);
        }
        //找连通块
        for(int i=1;i<=n;i++)
        {
            int fi=Find(i);
            if(!vis[fi])
            {
                vec.push_back(fi);// 有几个祖先就有几个连通块
                vis[fi]=1;
            }
            if(deg[i]%2) odd[fi]++; // 存储祖先是fi的图中的奇度数的点
        }
        cnt=0;
        vector<int>::iterator it;
        for(it=vec.begin();it!=vec.end();it++){
          //  cout<<"-> "<<(*it)<<endl;
            if(deg[(*it)]==0) continue; //孤立点哦
            if(odd[(*it)]==0) cnt++;//这个祖先所在的连通分量里没有 奇度点
            else cnt+=odd[(*it)]/2;
        }
        cout<<cnt<<endl; 
    }
    return 0;
}
/*
3 3
1 2
2 3
1 3

4 2
1 2
3 4

4 7 
1 2 
1 3 
1 4 
2 3 
2 4 
3 4 
3 3 
 
4 5 
1 2 
2 3 
4 4 
4 4 
4 4 

如果该连通分量是一个孤立的点,显然只需要0笔.
如果该连通分量是一个欧拉图或半欧拉图,只需要1笔.
连通分量并非一个(半)欧拉图时,需要(该图中奇数度的点数目/2)笔
*/
