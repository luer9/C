/*
 the best way to do it was to travel through each street of town only once. Naturally, he wanted to finish his trip at the same place he started, 
����ÿ���ֵ���һ�Σ����ص�ԭ��
Assume that Johnny lives at the junction ending the street appears first in the input with smaller number.
�Ե�һ���������С��junction��Ϊ���

If there was more than one such round trip, he would have chosen the one which, when written down as a sequence of street numbers is lexicographically the smallest. 
����ж�� ����� �ֵ��� ��С�Ľֵ�������
��Ŀ��֤�� ������ͨͼ
x��y�����˱�z,���Ƿ񹹳�ŷ����·��������ڣ�������ֵ�����С������ŷ����·
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
            dfs(edge[i].u+edge[i].v-s); //!��ȥһ����ͬ�� ʣ�µľ�����Ҫ�����ѵ�
            ans[cnt++]=i;//����Ǳߵı��
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
            m++;//��
            n=max(n,max(x,y));//����
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

���⣺
һ��������n������·�ڣ���Щ·����m���ֵ����ӣ�ĳ����Ҫ��ĳ��·�ڳ������������еĽֵ���ÿ���ֵ�ֻ��һ�Σ��ٻص������㣬���ҳ�һ�����е�·�ߣ�������������Ľֵ���ţ�����ж���·�ߣ�ѡ���ֵ�����С��һ�������
��֤��John�ļ���Ϊ��ʼ�����ŷ����·�ұ�֤�ֵ�����С,��Ϊdfs_fleury������������ŷ��·���Ǵ���������(����㱻�ŵ����������),����������Ҫ�������������ans������,����������,��
for(int i=1;i<=m;i++)ÿ�ζ��Ǵ�С����ѡ���뵱ǰ�ڵ������Ŀ��бߵ�(�������Ա�֤���������ֵ�����С).
*/