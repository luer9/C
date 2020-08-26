#include <bits/stdc++.h>
#define Max 2001
using namespace std;
struct Node
{
    int zs;
    double xs;
}node1[Max],node2[Max];
int main(){

    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>node1[i].zs>>node1[i].xs;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>node2[i].zs>>node2[i].xs;
    }
    int maxx=-1,cnt=0;
    map<int,double> mapp; mapp.clear();
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++){
            double xs=node1[i].xs*node2[j].xs;
            int zs=node1[i].zs+node2[j].zs;
            if(xs==0) continue;
            if(mapp[zs]==0.0){
                cnt++;
            }
            mapp[zs]+=xs;
            if(zs>maxx){maxx=zs;}
        }
    }
    if(cnt){
        cout<<cnt<<" "<<maxx<<" "<<fixed<<setprecision(1)<<mapp[maxx];
        for(int i=maxx-1;i>=0;i--){
            if(mapp[i]!=0.0){
                cout<<" "<<i<<" "<<fixed<<setprecision(1)<<mapp[i];
            }
        }
        cout<<endl;
    }
    return 0;
}