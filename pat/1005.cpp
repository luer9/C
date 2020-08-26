#include <bits/stdc++.h>
using namespace std;
map<int,string> mapp;
int main(){

    mapp[0]="zero";mapp[1]="one";mapp[2]="two";
    mapp[3]="three";mapp[4]="four";mapp[5]="five";
    mapp[6]="six";mapp[7]="seven";mapp[8]="eight";
    mapp[9]="nine";
    string s;
    int sum=0,len;
    cin>>s;
    len=s.length();
    for(int i=0;i<len;i++){
        sum+=s[i]-'0';
    }
    if(sum==0) cout<<mapp[0];
    stack <string> st;
    while(!st.empty()) st.pop();
    while(sum){
        int c=sum%10;
        sum/=10;
        st.push(mapp[c]);
    }
    if(!st.empty()) {
        cout<<st.top();
        st.pop();
    }
    while(!st.empty())
    {
        cout<<" "<<st.top();
        st.pop();
    }
    cout<<endl;
    return 0;
}