// 一个路径最短 一个时间最短 
// 跑两次dijkstra 
//一次跑路径（如果不唯一 输出时间最短的） 
//一次跑时间（如果不唯一 输出经过地点最少的） 
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define Max 505
using namespace std;
int visL[Max], visT[Max];//标记 
int preL[Max], preT[Max];//前驱 
int disL[Max], disT[Max];//dis 
int mapL[Max][Max], mapT[Max][Max];//
int numT[Max];// 求最快时间时 记录经过的地点数
int t[Max]; //求最短路径时 记录时间 
int n, m;
 
void dijkstraL(int st){
	memset(visL, 0, sizeof(visL));
	memset(disL, inf, sizeof(disL));
	memset(t, inf, sizeof(t));
	disL[st] = 0;
	t[st] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, minn = inf;
		for(int j = 0; j < n; j++){
			if(!visL[j] && disL[j] < minn){
				minn = disL[j];
				u = j;
			}
		}
		if(u == -1) break;
		visL[u] = 1;
		for(int v = 0; v < n; v++){
			if(!visL[v]){
				if(disL[v] > disL[u] + mapL[u][v]){
					disL[v] = disL[u] + mapL[u][v];
					preL[v] = u;
					t[v] = t[u] + mapT[u][v];
				}else if(disL[v] == disL[u] + mapL[u][v]){
					if(t[v] > t[u] + mapT[u][v]){
						t[v] = t[u] + mapT[u][v];
						preL[v] = u;
					}
				}
			}
		} 
	}
} 
void dijkstraT(int st){
	memset(visT, 0, sizeof(visT));
	memset(disT, inf, sizeof(disT));
	memset(numT, inf, sizeof(numT));
	disT[st] = 0;
	numT[st] = 1;
	for(int i = 0; i < n; i++){
		int u = -1, minn = inf;
		for(int j = 0; j < n; j++){
			if(!visT[j] && disT[j] < minn){
				minn = disT[j];
				u = j;
			}
		}
		if(u == -1) break;
		visT[u] = 1;
		for(int v = 0; v < n; v ++){
			if(!visT[v]){
				if(disT[v] > disT[u] + mapT[u][v]){
					disT[v] = disT[u] + mapT[u][v];
					preT[v] = u;
					numT[v] = numT[u] + 1;
				}else if(disT[v] == disT[u] + mapT[u][v]){
					if(numT[v] > numT[u] + 1){
						numT[v] = numT[u] + 1;
						preT[v] = u;
					}
				}
			}
		}
	}
} 
void dfsL(int i){
	if(preL[i] == i) return;
	dfsL(preL[i]);
	cout << " -> " << i; 
}
void dfsT(int i){
	if(preT[i] == i) return;
	dfsT(preT[i]);
	
	cout << " -> " << i;
}
int isEqual(int st,int end){
	while(st != end){
		if(preL[end] != preT[end]){
			return 0;
		}
		end = preL[end];
	}
	return true;
}
int main(){
	int u, v, l, t, dir, st, end;
	memset(mapL, inf, sizeof(mapL));
	memset(mapT, inf, sizeof(mapT));
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		preL[i] = preT[i] = i;
	} 
	for(int i = 0; i < m; i++){
		cin >> u >> v >> dir >> l >> t;
		if(dir == 0){
			mapT[v][u] = t;
			mapL[v][u] = l;
		}
		mapT[u][v] = t;
		mapL[u][v] = l;
	}
	cin >> st >> end;
	dijkstraT(st);

	dijkstraL(st);
	
	if(isEqual(st, end)){
		cout << "Distance = " << disL[end] << "; ";
	}else {
		cout << "Distance = " << disL[end] << ": " << st;
		dfsL(end);
		cout << endl;
	}
	cout << "Time = " << disT[end] << ": " << st;
	dfsT(end);
	cout << endl;
	return 0;
}
