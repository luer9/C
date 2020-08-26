// 相同的一层属于同一代    
//问题是让你找 人最多的同一代的人数 及相应的级别 
#include <bits/stdc++.h>
#define Max 101
using namespace std;
vector<int> vec[Max];
int n, m, id, k, sum[Max], level[Max];
int maxNum = -1, maxLev = -1;
void bfs(){
	queue<int> q;
	q.push(1);
	level[1] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		sum[level[u]]++;
		for(int v = 0; v < vec[u].size(); v++){
			level[vec[u][v]] = level[u] + 1;
			q.push(vec[u][v]);
		}
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
	bfs();
	for(int i = 0; i <= n; i++){
		if(sum[i] > maxNum){
			maxNum = sum[i];
			maxLev = i;
		}
	}
	cout << maxNum << " " << maxLev << endl; 
	return 0;
}
