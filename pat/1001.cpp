#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c[101],ind;
ll a,b,ans;
//void 分割  反
void divide(){
    while(ans){
        int cc=ans%10;
        c[ind++]=cc;
        ans/=10;
    }
}
int main()
{
    string anss="";
    ind=0;
    memset(c,0,sizeof(c));
    bool flag = false; //0的话为负数 否则为正数
    cin>>a>>b;
    ans = a+b;
    if(ans==0) {cout<<0<<endl;}
    else
    {
        if(ans<0) flag=false,ans=abs(ans);
        else flag=true;//正数
        divide();
        if(!flag) cout<<"-";
        if(ind<4)
        {
            for(int i=ind-1;i>=0;i--)
            {
                cout<<c[i];
            } 
            cout<<endl;
        }else{
            int index1=0;
            int cnt=0;
            for(int i=0;i<ind;i++)
            {
                anss+=(c[i]+'0');
                cnt++;
                if(cnt==3&&i!=ind-1)anss+=',',cnt=0;
            }
           for(int i=anss.length()-1;i>=0;i--)
           {
               cout<<anss[i];
           }
           cout<<endl;
        }
    }
    
   
   
    return 0;
}


// #include <iostream>
// using namespace std;
// int main() {
//     int a, b;
//     cin >> a >> b;
//     string s = to_string(a + b);
//     int len = s.length();
//     for (int i = 0; i < len; i++) {
//         cout << s[i];
//         if (s[i] == '-') continue;
//         if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
//     }
//     return 0;
// }