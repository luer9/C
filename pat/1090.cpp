#include <bits/stdc++.h>
#define Max 100050 
using namespace std;
vector<int> vec[Max]; 
int n, u, v, st, lev[Max];
double p, r;
void bfs(int st){
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(st);
	lev[st] = 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(v = 0; v < vec[u].size(); v++){
			lev[vec[u][v]] = lev[u] + 1;
			q.push(vec[u][v]);
		}
	}
}
int main(){
	
	memset(lev, 0, sizeof(lev));
	cin >> n >> p >> r;
	for(int i = 0; i < n;i ++){
		cin >> u;
		if( u != -1)
			vec[u].push_back(i);
		else st = i;
	}
	bfs(st);
	int maxx = -1, cnt = 0;
	for(int i = 0; i < n; i++){
		if(lev[i] > maxx){
			maxx = lev[i];
			cnt = 1;
		}else if(lev[i] == maxx){
			cnt++;
		}
	}
	cout << fixed << setprecision(2) << p*pow(1+r/100, maxx-1) << " " << cnt << endl;
	return 0;
}
