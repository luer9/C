#include <bits/stdc++.h> 
#define inf 0x3f3f3f3f
#define Max 222
using namespace std;
int n, k;
int weight[Max], mapp[Max][Max], w[Max], dis[Max], pre[Max];
int pt[Max], num[Max], vis[Max];
string st;
map<int, string> mapp1;
map<string,int> mapp2;
void dijkstra(int st){
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	for(int i = 0; i < n; i++){
		pre[i] = i;
	}
	dis[st] = 0;
	vis[st] = 1;
	w[st] = 0;
	num[st] = 1;
	for(int i = 1; i < n; i++){
		int u = -1, minn =inf;
		for(int j = 0; j < n; j++){
			if(!vis[j] && dis[j]<minn){
				minn = dis[j];
				u = j;
			}
		} 
	
		if(u == -1) break;
		vis[u] = 1;
		for(int v = 0; v < n; v++){
			if(!vis[v] && mapp[u][v] != inf){
				if(dis[v] > dis[u] + mapp[u][v]){
					dis[v] = dis[u] + mapp[u][v];
					w[v] = weight[v] + w[u];
					pre[v] = u;
					pt[v] = pt[u] + 1;
					num[v] = num[u];
				}else if(dis[v] == dis[u] + mapp[u][v]){
					num[v] += num[u];
					if(w[v] < weight[v] + w[u]){
						w[v] = weight[v] + w[u];
						pre[v] = u;
						pt[v] = pt[u] + 1;
					}else if(w[v] == weight[v] + w[u]){
						double avg1 = (weight[v] + w[u])*1.0 / (pt[u] + 1)*1.0;
						double avg2 = w[v] * 1.0 / pt[v] * 1.0;
						if(avg1 > avg2){
							pre[v] = u;
							pt[v] = pt[u] + 1;
						}
					}
				}
			}
		} 
	}
}
void dfs(int v){
	if(v == 0){
		cout << mapp1[v];
		return;
	}
	dfs(pre[v]);
	cout <<"->" << mapp1[v];
}
int main(){
	string u, v, name;
	cin >> n >> k >> st;
	mapp1[0] = st; mapp2[st] = 0;
	memset(mapp, inf, sizeof(mapp));
	for(int i = 1; i < n; i++){
		cin >> name;
		mapp1[i] = name;
		mapp2[name] = i;
		cin >> weight[i];
	}
	for(int i = 0; i < k; i++){
		cin >> u >> v;
		int uid = mapp2[u];
		int vid = mapp2[v];
		cin >> mapp[uid][vid];
		mapp[vid][uid] = mapp[uid][vid];
	}
	dijkstra(0);
	int rom = mapp2["ROM"];
	cout << num[rom] << " " << dis[rom] << " " << w[rom] <<" "<< w[rom]/pt[rom] << endl;
	dfs(rom);
	return 0;
}
