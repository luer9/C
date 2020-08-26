/*
ŷ����·
����ͼ
�ж� ��ͨ+����Ϊż��
!!!!!ע���ʼ������

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#define Max 1002
#define ll long long
using namespace std;
// int vis[Max];
int deg[Max];
int fa[Max];
int n,m,u,v;
void init()
{
   // memset(vis,0,sizeof(vis));
    memset(deg,0,sizeof(deg));
    for(int i=1;i<=n;i++) fa[i]=i;
}
int Find(int x)
{
    if(x==fa[x]) return x;
    else return fa[x]=Find(fa[x]);
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
    while(cin>>n){
        if(n==0) break;
        init(); //remember
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            deg[u]++,deg[v]++;
            mix(u,v);//�ϲ�
        }
        int flag=false;
        int cnt=0;   //�ж���ͨ��
        for(int i=1;i<=n;i++)
        {
            if(fa[i]==i) cnt++; //��������
            if(deg[i]%2!=0)
            {
                flag=true;
            }
        }
        if(flag||cnt!=1) cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;
}