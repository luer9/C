#include <bits/stdc++.h>
#define ll long long
#define Max 101
using namespace std;
struct People
{
    char s[22];
    ll st,en;//开始时间结束时间
}peo[101];
int m;
int cmp1(People a,People b){
    return a.st<b.st;
}
int cmp2(People a,People b){
    return a.en>b.en;
}
int main(){

   // ios::sync_with_stdio(false);
    //cin>>m;
    int h1,m1,s1,h2,m2,s2;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%s %d:%d:%d %d:%d:%d",peo[i].s,&h1,&m1,&s1,&h2,&m2,&s2);
        peo[i].st=h1*3600+m1*60+s1;
        peo[i].en=h2*3600+m2*60+s2;
    }
    sort(peo,peo+m,cmp1);
    printf("%s ",peo[0].s);
    sort(peo,peo+m,cmp2);
    printf("%s",peo[0].s);
    return 0;
}