/*
通话 每分钟消费一个确定的价钱 ，取决于打电话的时间
任务是计算每月的花费，
*/
#include <bits/stdc++.h>
#define Max 1005
using namespace std;
typedef pair <int, int> pii;
int n;
int rate[30]; // 24小时 每个小时的收费
//消费记录
struct record{
    char name[21];
    int month, d, h, m; //时间
    int status;//状态
    bool operator < (const record & r) const{
        if(strcmp(name ,r.name) < 0) return true;
        if(strcmp(name ,r.name) == 0) {
            if(d < r.d) return true;
            if(d == r.d) {
                if(h < r.h) return true;
                if(h == r.h) {
                    if(m < r.m) return true;
                }
            } 
        }
        return false;
    }
}rec[Max];
//每个人通话记录的映射
map< string, vector<record> > mapp;

//得到时间和花费
pii get_TC(int d, int h, int m) {
    int tol_time = 0, tol_cost = 0, rt = 0;
    tol_time += d * 24 * 60 + h * 60 + m;
    /*-----花费计算-------*/
    for(int i = 0; i < 24; i++) rt += rate[i] * 60; //打一整天需要的钱
    tol_cost += d * rt + m * rate[h];
    for(int i = 0; i < h; i++) {
        tol_cost += rate[i] * 60;
    } 
    /*-------------------*/
    return make_pair(tol_time, tol_cost); 
}
void ac() {
    
    //把每个人的通话记录用vector记录起来。 然后用map映射
    for(int i = 0; i < n-1; i++){
        if(strcmp(rec[i].name,rec[i+1].name) == 0) {
            if(rec[i].status == 1 && rec[i+1].status == 0) {
                // cout << "name: "<< rec[i].name << endl;
                mapp[rec[i].name].push_back(rec[i]);
                mapp[rec[i].name].push_back(rec[i+1]);
            }
        }
    }

    // cout << "*******" << endl;

    //输出
    map<string, vector<record> > ::iterator it;
    for(it = mapp.begin(); it != mapp.end(); it++) {
        // cout << "!!!!!!!" << it -> first << endl;
        //个人的消费记录
        vector<record> rs = it -> second;
        cout << it -> first;
        printf(" %02d\n", rs[0].month);
        int tol_cost = 0, tol_time = 0;
        for(int i = 0; i < rs.size(); i+=2) {
            pii st = get_TC(rs[i].d, rs[i].h, rs[i].m);
            pii en = get_TC(rs[i+1].d, rs[i+1].h, rs[i+1].m);
            tol_time = en.first - st.first;
            // cost = (en.second - st.second)*1.0 / 100;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", rs[i].d, rs[i].h, rs[i].m, rs[i+1].d, rs[i+1].h, rs[i+1].m, tol_time, (en.second - st.second)*1.0/100);
            tol_cost += en.second - st.second;
            // cout << " Cost " << tol_cost << endl;
        }
        // cout << " Cost!! " << tol_cost << endl;
        printf("Total amount: $%.2lf\n",tol_cost*1.0 / 100);
    }
}
int main() {
    // ios::sync_with_stdio (false);
    for(int i = 0; i < 24; i++) {
        scanf("%d",&rate[i]);
    }
    scanf("%d",&n);
    getchar();
    char sta[10];
    for(int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d:%d %s",rec[i].name, &rec[i].month, &rec[i].d, &rec[i].h, &rec[i].m, sta);
        if(sta[1] == 'n'){
            rec[i].status = 1;
        }else rec[i].status = 0;
    }
    sort(rec, rec + n);
    // for(int i = 0; i < n; i++) {
    //     cout << "--> " << rec[i].name << "  " << rec[i].status << endl;
    // }
    ac();
    return 0;
}