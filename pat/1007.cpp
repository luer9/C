#include <bits/stdc++.h>
#define Max 10001
using namespace std;
int n,a[Max];
int main(){
    cin>>n;
    int l=0,r=n-1,sum=-1,temp=0,temp_l=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        temp+=a[i];
        if(temp<0){
            temp=0;
            temp_l=i+1;//标记一下
        }
        else if(temp>sum){
            sum=temp;
            l=temp_l;
            r=i;
        }
    }
    if(sum<0) sum=0;
    cout<<sum<<" "<<a[l]<<" "<<a[r]<<endl;
    return 0;
}