#include <bits/stdc++.h>
#define Max 100005
using namespace std;
double p, r;
int n, u, rt;
vector<int> vec[Max];
int vis[Max];
int high[Max];
int maxH = -1;
void bfs(){
	queue<int> q;
	q.push(rt);
	high[rt] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(high[u] > maxH){
			maxH = high[u];
		}
		for(int i = 0; i < vec[u].size(); i++){
			high[vec[u][i]] = high[u] + 1;
			q.push(vec[u][i]);
		}
	}
}
int main(){
	memset(high, -1, sizeof(high));
	cin >> n >> p >> r;
	for(int i = 0; i < n; i++){
		cin >> u;
		if(u == -1) rt = i;
		else {
			vec[u].push_back(i);
		} 
	}
	bfs();
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(high[i] == maxH){
			cnt ++;
		}
	}
	cout << fixed << setprecision(2) << p * pow(1+r/100, maxH ) << " " << cnt << endl;
	return 0;
}
