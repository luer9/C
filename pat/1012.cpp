/*
  刚开始得了21分 因为没有处理排名并列的情况。哎！！
 */
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
struct Stu
{
    string id;
    int  cplus, math, eng, ave;
    int rank_c, rank_m, rank_e, rank_a;
}a[2002];
int n,m;
int cmpa(Stu a, Stu b){
    return a.ave > b.ave;
}
int cmpc(Stu a, Stu b){
    return a.cplus > b.cplus;
}
int cmpm(Stu a,Stu b){
    return a.math > b.math;
}
int cmpe(Stu a,Stu b){
    return a.eng > b.eng;
}
int main() {

    map<string,int> mapp;
    mapp.clear();
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> a[i].id >> a[i].cplus >> a[i].math >> a[i].eng ;
        a[i].ave = (a[i].cplus + a[i].math + a[i].eng) / 3;
        mapp[ a[i].id ] = 1;
        a[i].rank_c = a[i].rank_e = a[i].rank_m = a[i].rank_a = 0;
    }
    //a c m e
    string temp;
    for(int i = 0; i < m; i++){
        cin >> temp;
        if(mapp[temp] == 0) {
            cout << "N/A" << endl ;
            continue;
        }
        int minn = inf ,mine = inf, minm = inf, minc = inf ,mina = inf;
        char ide ,idm ,idc ,ida;  
        sort(a, a+n, cmpe);
        for(int i = 0;i < n; i++){
            a[i].rank_e = i+1;
            if (i > 0 && a[i].eng == a[i-1].eng) {
                a[i].rank_e = a[i-1].rank_e;
            }
        }        
        sort(a, a+n, cmpm);
        for(int i = 0;i < n; i++){
            a[i].rank_m = i+1;
            if (i > 0 && a[i].math == a[i-1].math) {
                a[i].rank_m = a[i-1].rank_m;
            }
        }          
        sort(a, a+n, cmpc);
        for(int i = 0;i < n; i++){
            a[i].rank_c = i+1;
            if (i > 0 && a[i].cplus == a[i-1].cplus) {
                a[i].rank_c = a[i-1].rank_c;
            }
        }    
        sort(a, a+n, cmpa);
        for (int i = 0;i < n; i++){
            a[i].rank_a = i+1;
            if (i > 0 && a[i].ave == a[i-1].ave) {
                a[i].rank_a = a[i-1].rank_a;
            }
        }
        // minn = min(mina,min(min(minc,minm),mine));
      //  cout << minn << " " << id << endl;
        // if (minn == mina) {
        //     cout << minn << " " << ida <<endl;
        //     continue;
        // }
        // if (minn == minc) {
        //     cout << minn << " " << idc <<endl;
        //     continue;
        // }
        // if (minn == minm) {
        //     cout << minn << " " << idm <<endl;
        //     continue;
        // }
        // if (minn == mine) {
        //     cout << minn << " " << ide <<endl;
        //     continue;
        // }
        for (int i = 0; i < n; i++){
            if (a[i].id == temp){
                int rank = min(a[i].rank_a,min(min(a[i].rank_c,a[i].rank_e),a[i].rank_m));
                if (a[i].rank_a == rank)
                {
                    cout << rank << " A"<<endl;
                    break;
                }
                if (a[i].rank_c == rank)
                {
                    cout << rank << " C"<<endl;
                    break;
                }
                if (a[i].rank_m == rank)
                {
                    cout << rank << " M"<<endl;
                    break;
                }
                if (a[i].rank_e == rank)
                {
                    cout << rank << " E"<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}