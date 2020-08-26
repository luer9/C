/*
ͨ�� ÿ��������һ��ȷ���ļ�Ǯ ��ȡ���ڴ�绰��ʱ��
�����Ǽ���ÿ�µĻ��ѣ�
*/
#include <bits/stdc++.h>
#define Max 1005
using namespace std;
typedef pair <int, int> pii;
int n;
int rate[30]; // 24Сʱ ÿ��Сʱ���շ�
//���Ѽ�¼
struct record{
    char name[21];
    int month, d, h, m; //ʱ��
    int status;//״̬
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
//ÿ����ͨ����¼��ӳ��
map< string, vector<record> > mapp;

//�õ�ʱ��ͻ���
pii get_TC(int d, int h, int m) {
    int tol_time = 0, tol_cost = 0, rt = 0;
    tol_time += d * 24 * 60 + h * 60 + m;
    /*-----���Ѽ���-------*/
    for(int i = 0; i < 24; i++) rt += rate[i] * 60; //��һ������Ҫ��Ǯ
    tol_cost += d * rt + m * rate[h];
    for(int i = 0; i < h; i++) {
        tol_cost += rate[i] * 60;
    } 
    /*-------------------*/
    return make_pair(tol_time, tol_cost); 
}
void ac() {
    
    //��ÿ���˵�ͨ����¼��vector��¼������ Ȼ����mapӳ��
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

    //���
    map<string, vector<record> > ::iterator it;
    for(it = mapp.begin(); it != mapp.end(); it++) {
        // cout << "!!!!!!!" << it -> first << endl;
        //���˵����Ѽ�¼
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