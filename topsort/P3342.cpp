/*
 HH is 3xian's master and, at the same time, 3xian is HH's master,which is quite illegal! 
 To avoid this,please help us to judge whether their relationship is legal or not. 
判断有没有环
*/
#include <bits/stdc++.h>
#define Max 101
using namespace std;
vector<int> vec[Max];
int in_deg[Max];
queue<int>q;
int n,m;
void init(int nn)
{
    for(int i=0;i<=nn;i++)
    {
        vec[i].clear();
    }
    while(!q.empty()) q.pop();
    memset(in_deg,0,sizeof(in_deg));
}
int topsort()
{
    for(int i=0;i<n;i++)
    {
        if(in_deg[i]==0)
        {
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cnt++;
        for(int v=0;v<vec[u].size();v++)
        {
            in_deg[vec[u][v]]--;
            if(!in_deg[vec[u][v]])
            {
                q.push(vec[u][v]);
            }
        }
    }
    /*
    if(cnt==n)
    {
        return 1;//有向无环图
    }else return 0;//非 有向无环图
     */
    return cnt==n;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        init(n);
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            vec[u].push_back(v);
            in_deg[v]++;
        }
        bool ans=topsort();
        if(ans==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}