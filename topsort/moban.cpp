#include <bits/stdc++.h>
#define Max 505
using namespace std;
vector<int> vec[Max]; //vec 存图
priority_queue<int,vector<int>,greater<int> > q; //优先队列
int in_deg[Max];//入度
int ans[Max];
int n,m;
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

    if(cnt!=n) cout<<"-1"<<endl; //环
    else {
        cout<<ans[0];
        for(int i=1;i<cnt;i++)
            cout<<" "<<ans[i];
        cout<<endl;
    }
}