#include <bits/stdc++.h>
#define Max 101
using namespace std;
int n,m,u,v,k;
int maxLevel;
int ans[Max];
struct Node
{
    int lev;
    vector<int>vec;//孩子
    Node(){
        lev=0;
        vec.clear();
    }
}node[Max];
void bfs(int rt){
    queue<int>q;
    while(!q.empty()) q.pop();
    node[rt].lev=1;
    q.push(rt);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(node[cur].vec.size()==0){
            ans[node[cur].lev]++;
            if(node[cur].lev>maxLevel){
                maxLevel=node[cur].lev;
            }
            continue;
        }
        for(int i=0;i<node[cur].vec.size();i++)
        {
            int nex=node[cur].vec[i];
            node[nex].lev=node[cur].lev+1;
            q.push(nex);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    memset(ans,0,sizeof(ans));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>k;
        for(int j=0;j<k;j++)
        {
            cin>>v;
            node[u].vec.push_back(v);
            //u的孩子是v
        }
    }
    maxLevel=-1;
    bfs(1);
    for(int i=1;i<=maxLevel;i++){
        cout<<ans[i];
        if(i!=maxLevel) cout<<" ";
    }cout<<endl;
    return 0;
}