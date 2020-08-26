/*
 the best way to do it was to travel through each street of town only once. Naturally, he wanted to finish his trip at the same place he started, 
经过每个街道且一次，最后回到原点
Assume that Johnny lives at the junction ending the street appears first in the input with smaller number.
以第一个输入的最小的junction作为起点

If there was more than one such round trip, he would have chosen the one which, when written down as a sequence of street numbers is lexicographically the smallest. 
如果有多个 就输出 字典序 最小的街道号序列
题目保证是 无向连通图
x和y构成了边z,问是否构成欧拉回路，如果存在，就输出字典序最小的那条欧拉回路
*/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#define Maxn 66
#define Maxm 2222
using namespace std;
int n,m,x,y,z,cnt,st;
int deg[Maxn],vis[Maxm],ans[Maxm];
struct Node
{
    int u,v;
}edge[Maxm];
void init()
{
    cnt=0,n=0,m=0,cnt=0,st=0;
    memset(deg,0,sizeof(deg));
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
}
void dfs(int s)
{
    for(int i=1;i<=m;i++)
    {
        if(!vis[i]&&((edge[i].u==s)||(edge[i].v==s)))
        {
            vis[i]=1;
            dfs(edge[i].u+edge[i].v-s); //!减去一个相同的 剩下的就是需要继续搜的
            ans[cnt++]=i;//存的是边的编号
        }

    }
}  
      // if(!vis[i]&&(edge[i].u==s))
        // {
        //     vis[i]=1;
        //     dfs_fleury(edge[i].v);
        //     ans[cnt++]=i;
        // }
        // if(!vis[i]&&(edge[i].v==s))
        // {
        //     vis[i]=1;
        //     dfs_fleury(edge[i].u);
        //     ans[cnt++]=i;
        // }
int main(){

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // ios::sync_with_stdio(false);
    while(scanf("%d%d",&x,&y)&&x&&y)
    {
        init();
        st=min(x,y);
        do{
            scanf("%d",&z);
            edge[z].u=x,edge[z].v=y;
            deg[x]++,deg[y]++;
            m++;//边
            n=max(n,max(x,y));//顶点
        }while(scanf("%d%d",&x,&y)&&x&&y);
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(deg[i]%2){flag=true;break;}
        }
        if(flag) 
        {
            printf("Round trip does not exist.\n");
            continue;
        } 
        dfs(st); 
        for(int i=cnt-1;i>=0;i--)
        {
            printf("%d",ans[i]);
            if(i!=0) cout<<" ";
            else cout<<endl;
        }     
    }
    return 0;
}
/*

题意：
一个城镇有n个二叉路口，这些路口由m条街道连接，某人想要从某个路口出发，经过所有的街道且每条街道只走一次，再回到出发点，让找出一个可行的路线，依次输出经过的街道编号，如果有多条路线，选择字典序最小的一条输出。
保证从John的家作为起始点输出欧拉回路且保证字典序最小,因为dfs_fleury这个函数输出的欧拉路径是从起点逆序的(即起点被放到了最后才输出),所以我们需要把最后结果保存在ans数组中,最后逆序输出,且
for(int i=1;i<=m;i++)每次都是从小到大选择与当前节点相连的可行边的(这样可以保证输出结果的字典序最小).
*/