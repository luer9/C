// 相同的一层属于同一代    
//问题是让你找 人最多的同一代的人数 及相应的级别 
#include <bits/stdc++.h>
#define Max 101
using namespace std;
vector<int> vec[Max];
int n, m, id, k, sum[Max];
int maxNum = -1, maxLev = -1;
void dfs(int u, int lev){
	sum[lev] ++;
	for(int i = 0; i < vec[u].size(); i++){
		dfs(vec[u][i], lev+1);
	}
}
int main(){
	memset(sum, 0, sizeof(sum));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int child;
		cin >> id >> k;
		for(int j = 0; j < k; j++){
			cin >> child;
			vec[id].push_back(child);
		}
	}
	dfs(1, 1);
	for(int i = 0; i <= n; i++){
		if(sum[i] > maxNum){
			maxNum = sum[i];
			maxLev = i;
		}
	}
	cout << maxNum << " " << maxLev << endl; 
	return 0;
}
