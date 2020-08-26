#include <bits/stdc++.h>
#define Max 111
using namespace std;
int n,m,u,v,k;
int maxLevel;
int ans[Max];
vector<int> vec[Max];
void dfs(int cur,int dep){
    if(vec[cur].size()==0){
        ans[dep]++;
        maxLevel=max(dep,maxLevel);
        return ;
    }
    for(int i=0;i<int(vec[cur].size());i++){
        dfs(vec[cur].at(i),dep+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    memset(ans,0,sizeof(ans));
    for(int i=0;i<=101;i++)vec[i].clear();
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>k;
        for(int j=0;j<k;j++){
            cin>>v;
            vec[u].push_back(v);
        }
    }
    maxLevel=-1;
    dfs(1,0);
    for(int i=0;i<=maxLevel;i++){
        cout<<ans[i];
        if(i!=maxLevel) cout<<" ";
    }
    cout<<endl;
    return 0;
}