#include <bits/stdc++.h>
#define Max 505
using namespace std;
int deg[Max];
int n, m;
int u, v;
int vet = 0, vis[Max];
vector <int> vec[Max]; 
void dfs(int rt){
	if(vis[rt]) return;
	vis[rt] = 1;
	vet++;
	for(int i = 0; i < vec[rt].size(); i++){
		dfs(vec[rt][i]);
	}
}
int main(){
	int cnt1 = 0, cnt2 = 0;
	memset(deg, 0, sizeof(deg));
	memset(vis, 0, sizeof(vis));
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		deg[u] ++;
		deg[v] ++;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		cout << deg[i];
		if(i!=n) cout << " ";
		if(deg[i] % 2 == 0 ){
			cnt2 ++;
		}else cnt1++;
	}
	cout << endl;
	if(vet != n) {
		cout << "Non-Eulerian" << endl;
		return 0;
	}
//	cout << ":-> " << cnt1 << " " << cnt2 << endl;
	if(cnt1 == 2 && cnt2 == n - 2) {
		cout << "Semi-Eulerian" << endl;
	}else if(cnt1 == 0 && cnt2 == n){
		cout << "Eulerian" << endl;
	}else cout << "Non-Eulerian" << endl;
	return 0;
}
/*
判断这个图是欧拉图 还是欧拉路径 还是 都不是 
图的前提是 连通…… 否则会在第3个测试点错误！！！！！！！ 
*/
