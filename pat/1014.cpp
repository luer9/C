/*
N�����ڣ�M��ÿ�����ڻ������������ֵ��k�ǹ˿͵�����(���1-K)��q�ǹ˿Ͳ�ѯ������
�ڶ����� k���˿Ͱ���ҵ���ʱ��
q���˿��ʵ��� ����ʲôʱ���ܰ���ҵ��
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define debug  cout<<"-->"<<endl
#define debug1  cout<<"***"<<endl
using namespace std;
int n, m, k, q;
int cost[1002];
int Q[1002];
int pre[1002];//ÿ�������ڰ���ҵ���˵ı��
map<int, int> mapp;
void solve() {
    queue <int > qu[20];
    for(int i = 1; i <= n; i++) {
        while(!qu[i].empty()) {
            qu[i].pop();
        }
//        debug;
    } 
    int id = 1, flag, flag1;
    while(1) {
        flag = 1;
        while (flag) {
//            debug;
            flag1 = 0;
            for(int i = 1; i <= n; i++) {
                
                if(qu[i].size() != m && id <= k){
//                	debug1;
				    qu[i].push(id);
                    flag1 = 1;
                    id++;
                }
           } 
           if(!flag1) flag = 0;
        }
//		cout << "ready: " << id << endl; 
        int minn = inf, win_id = inf;//��С����ʱ�䣬������
        for(int i = 1; i <= n; i++) {
//            debug1;
            if(!qu[i].empty()){
                int id1 = qu[i].front();
//                cout << "**id1:" << id1 << endl;
                if(!pre[i]) {
                    mapp[id1] = 0 + cost[id1];
                }else { 
                    mapp[id1] = mapp[pre[i]] + cost[id1] ;
                }
                pre[i] = id1;
                qu[i].pop();
                if(mapp[id1] < minn) {
                    minn = mapp[id1];
                    win_id = i;
                }
            }
        }
//        cout << minn << ":" << win_id <<"  id��"<< id << endl;
        if(id <= k) {
//        	cout << "--> "<< id << endl;
            qu[win_id].push(id);
            id++;
        }

        int flag2 = 0;
        for(int i = 1; i <= n; i++) {
            if(qu[i].size() != 0) {
                flag2 = 1;
            }
        }
        if(!flag2) break;
    }
   
}
int main() {

    memset(pre, 0, sizeof(pre));
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 1; i <= n; i++) mapp[i] = 0;
    for(int i = 1; i <= k; i++) {
        scanf("%d",&cost[i]);
    }
//    cout << "-->" <<endl;
    solve();
//    cout << "****" << endl;
//    for (int i = 1; i <= k; i++) {
//        cout <<i<<" : "<< mapp[i] <<endl;
//    }
    int flag = 0;
     for(int i = 0; i < q; i++) {
         scanf("%d",&Q[i]);
         int h = mapp[Q[i]] / 60 + 8;
         int min = mapp[Q[i]] % 60;
         if(!flag)
         	printf("%02d:%02d\n",h,min); 
         else printf("sorry\n"); 
		 if(h>=17) flag = 1;
     }
    return 0;
}
