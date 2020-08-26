#include <bits/stdc++.h>
#define Max 2001
using namespace std;
struct Node
{
    int zs;
    double xs;
}node[Max];
int n,m;
int main(){
    int cnt=0,zs;
    double xs,ans[Max]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>node[i].zs>>node[i].xs;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>zs>>xs;
        for(int j=0;j<n;j++){
            ans[zs+node[j].zs]+=(node[j].xs*xs);
        }
    }
    for(int i=0;i<=2000;i++){
        if(ans[i]!=0) cnt++;
    }
    cout<<cnt;
    for(int i=2000;i>=0;i--){
        if(ans[i]!=0){
            cout<<" "<<i<<" "<<fixed<<setprecision(1)<<ans[i];
        }
    }
    return 0;
}