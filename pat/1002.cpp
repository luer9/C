//注意精确!!
#include <bits/stdc++.h>
using namespace std;
int k;
double n,an;
int main()
{
    double maxx=-1.0;//最大的指数
    int cnt=0;
    map<double,double> mapp;
    mapp.clear();
    for(int i=0;i<2;i++)
    {
         cin>>k;
         for(int j=1;j<=k;j++)
         {
             cin>>n>>an;
             mapp[n]+=an;
             if(n>maxx) maxx=n;
         }
    }
    for(int i=0;i<=maxx;i++)
    {
        if(mapp[i]!=0) cnt++;
    }
    cout<<cnt;
    for(int i=maxx;i>=0;i--)
    {
        if(mapp[i]!=0) cout<<" "<<i<<" "<<fixed<<setprecision(1)<<mapp[i];
    }
    cout<<endl;
    return 0;
}