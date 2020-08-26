/*
ио 6s
об 4s
╬╡ж╧ 5s
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[101]={0};
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i-1])//ио
        {
            ans=ans+(a[i]-a[i-1])*6+5;
        }else if(a[i]<=a[i-1])
        {
            ans=ans+(a[i-1]-a[i])*4+5;
        }
    }
    cout<<ans<<endl;
    return 0;
}