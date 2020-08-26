/*
����ģ�� +���ȶ���
*/
#include <bits/stdc++.h>
#define Max 505
using namespace std;
vector<int> vec[Max]; //vec ��ͼ
priority_queue<int,vector<int>,greater<int> > q; //���ȶ���
int in_deg[Max];//���
int ans[Max];
int n,m;
void init()
{
    memset(in_deg,0,sizeof(in_deg));
    for(int i=0;i<=n;i++)
    {
        vec[i].clear();
    }
    while(!q.empty())
    {
        q.pop();
    }
}
void topsort()
{
    for(int i=1;i<=n;i++)
    {
        if(in_deg[i]==0)
        {
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        ans[cnt++]=u;
        for(int v=0;v<vec[u].size();v++)
        {
            in_deg[vec[u][v]]--;
            if(!in_deg[vec[u][v]])
            {
                q.push(vec[u][v]);
            }
        }
    } 

    if(cnt!=n) cout<<"-1"<<endl; //��
    else {
        cout<<ans[0];
        for(int i=1;i<cnt;i++)
            cout<<" "<<ans[i];
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
       init();
       int u,v;
       for(int i=0;i<m;i++)
       {
           cin>>u>>v;
           vec[u].push_back(v); 
           in_deg[v]++;
       }
       topsort();
    }
    return 0;
}