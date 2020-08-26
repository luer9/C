#include <bits/stdc++.h>
#define Max 202
#define inf 0x3f3f3f3f
using namespace std;
int mapp[Max][Max];
int n, m;
int u, v, c;
int q, k;
int a[Max], vis[Max];
void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			mapp[i][j] = mapp[j][i] = inf;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	init();
	for(int i = 0; i < m; i++){
		cin >> u >> v >> c;
		mapp[u][v] = mapp[v][u] = c; 
	}
	int minn = inf, dis = 0, id = -1; 
	cin >> q;
	for(int Case = 1; Case <= q; Case++){
		memset(vis, 0, sizeof(vis));
		dis = 0;
		cin >> k;
		for(int i = 1; i <= k; i++){
			cin >> a[i];
			vis[a[i]] = 1;
		}
		 
		int flag1 = 0, flag2 = 0; // 1判断是否可达， 2 判断是否含有所有点 
		int flag3 = 0; //是否是环 
		for(int i = 1; i <= n; i++){
			if(vis[i] != 1){
				flag2 = 1; //不含有全部点   
			}
		}
		for(int i = 2; i <= k; i++){
			dis += mapp[a[i-1]][a[i]];
		}
		if(a[1] != a[k]) flag3 = 1;
		if(dis >= inf) flag1 = 1;//不可到达
		if(flag1) {
			cout << "Path " << Case << ": " << "NA (Not a TS cycle)" << endl;
			continue;
		}
		if(flag2) {
			cout << "Path " << Case << ": " << dis <<" (Not a TS cycle)" << endl;
			continue;
		}
		if(flag3) {
			cout << "Path " << Case << ": " << dis <<" (Not a TS cycle)" << endl;
			continue;
		} 
		if(k == n + 1) {
			cout << "Path " << Case << ": " << dis <<" (TS simple cycle)" << endl;
		}else if(k > n + 1){
			cout << "Path " << Case << ": " << dis <<" (TS cycle)" << endl;	
		}
		if(dis < minn && !flag1 && !flag2)  {
			minn = dis;
			id = Case;
		}
	}
	cout << "Shortest Dist(" << id << ")" << " = " << minn << endl;
	return 0;
}
