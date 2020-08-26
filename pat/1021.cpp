#include <bits/stdc++.h>
#define Max 10002
using namespace std;
vector<int> vec[Max], res;
int vis[Max];
int n, u, v;
int temp = 0, maxH = 0;
void dfs(int rt, int dept){
	vis[rt] = 1;
	if(dept > temp){
		temp = dept;
	}
	for(int i = 0; i < vec[rt].size(); i++){
		if(!vis[vec[rt][i]]) 
			dfs(vec[rt][i], dept+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n-1; i ++){
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u); 
	}
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		int cnt = 1, flag = 0;
		dfs(i, 1);
		for(int j = 1; j <= n; j++){
			if(!vis[j]){ //不连通的情况 
				dfs(j, 1);
				cnt ++;
				flag = 1;
			}
		}
		if(flag) {
			cout << "Error: " << cnt << " components" << endl;
			return 0;
		}
		if(temp > maxH){
			res.clear();
			res.push_back(i);
			maxH = temp;
		}else if(temp == maxH){
			res.push_back(i);
		}
		temp = 0;
	}
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	return 0;
}








