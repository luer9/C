/*
欧拉路径
题意：盘子上都写了个字，盘子必须按照一定的顺序排列，排序的规则是每个单词的开头与上一个单词的结尾字母相同
要判断所有的盘子是否能按照上述的规则排序
并查集+欧拉路 判断
ps:并查集判断连通性
这里构造图看成有向图 ----->
有向图判断存在欧拉回路或欧拉通路的条件是
只存在这样两个点：一个点入度等于出度+1，另一个点入度=出度-1，其他每个点入度都等于出度，或者每个点入度都等于出度。
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#define ll long long
#define Max 100005
using namespace std;
string s;
int n,m;
int vis[30],fa[30];//vis判断字母是否出现,fa数组用于并查集
int out[30],in[30];//存每个字母的入度和出度
struct Node
{
    int u,v;
}edge[Max];
void init()
{
    memset(vis,0,sizeof(vis));
    memset(out,0,sizeof(out));
    memset(in,0,sizeof(in));
    for(int i=0;i<26;i++)fa[i]=i;
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
int If_connect()
{
    //合并
    for(int i=0;i<n;i++){
        int u=edge[i].u,v=edge[i].v;
        if(u!=v&&Find(u)!=Find(v))
        {
            mix(u,v);
        }
    }
    //判断连通性
    int f=-1,k;
    for(k=0;k<26;k++)
    {
        if(!vis[k]) continue;
        if(f==-1) f=k; //f记录第一个存在的字符
        else if(Find(f)!=Find(k)) break;//祖先不一样 说明不连通
    }
    if(k<26) return 0;
    return 1;
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        init();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            int u=s[0]-'a',v=s[s.length()-1]-'a';
            edge[i].u=u,edge[i].v=v;
            vis[u]=vis[v]=1;
            out[u]++,in[v]++; // 出度  入度
            //每个字母当成一个点
        }
        bool flag=true;
        int cnt1=0,cnt2=0;
        for(int i=0;i<26;i++){
            if(!vis[i]) continue; 
            //入度和出度不等
            if(abs(out[i]-in[i])>1){flag=false;break;}
            if(out[i]-in[i]==1)//如果有必须有一个
            {
                cnt1++; 
                if(cnt1>1){flag=false; break; }
            }
            if(out[i]-in[i]==-1)//如果有必须有一个
            {
                cnt2++;
                if(cnt2>1) {flag=false;break; }
            }
        }
        /*
        出度与入度都相等；或者除两个顶点外
        其余顶点的出度与入度都相等，而这两个顶点中一个顶点的出度-入度==1，
        另一个出度-入度==-1；
        */
        if(cnt1!=cnt2) flag=false; 
        if(!If_connect()) flag=false;
        if(flag) cout<<"Ordering is possible."<<endl;
        else cout<<"The door cannot be opened."<<endl;

    }
    return 0;
} 
