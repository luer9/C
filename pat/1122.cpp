/*
 find a simple cycle that contains every vertex in a graph
*/
#include <bits/stdc++.h>
#define Max 202
using namespace std;
int n, m, mapp[Max][Max], k, n1, flag;
int v[Max*10], u, vv, vis[Max];
//因为v的范围可能超过 Max 所以……最后一个样例一直没过 
int main() {
	memset(mapp,0,sizeof(mapp));
	memset(v, 0, sizeof(v));
	cin >> n >> m;

	for(int i = 1; i <= m; i++) {
		cin >> u >> vv;
		mapp[u][vv] = mapp[vv][u] = 1;
	}
	cin >> k;
	while(k--) {
		flag = 0;
		memset(vis, 0, sizeof(vis));
		memset(v, 0, sizeof(v));
		cin >> n1;
		for(int i = 1; i <= n1; i++) {
			cin >> v[i];
			vis[v[i]] = 1;
		}
		//没有覆盖全部点 
		for(int i = 1; i <= n; i++){
			if(!vis[i]) {
				flag = 1;
				break;
			}
		}		
		for(int i = 2; i <= n1; i++){
			int a = v[i-1];
			int b = v[i];
			if( !mapp[a][b] ){
				flag = 1;
				break;
			}
		} 
		//每个点都要经过 ， 所以必须有n+1个点
		if(n1 != n+1 || flag || v[1] != v[n1]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
