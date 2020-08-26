#include <bits/stdc++.h>
#define Max 2001
using namespace std;
int main(){
    double a,b,c,ans=1;
    char aa,bb,cc;
    for(int i=0;i<3;i++)
    {
        cin>>a>>b>>c;
        double maxx=max(a,max(b,c));

        if(maxx==a){aa='W';}
        if(maxx==b){aa='T';}
        if(maxx==c){aa='L';}
        ans*=maxx;
        cout<<aa<<" ";
    }
    ans=(ans*0.65-1)*2;
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}