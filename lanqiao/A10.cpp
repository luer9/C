#include <bits/stdc++.h>
#define Max 1111
#define inf 0x3f3f3f3f 
using namespace std;
struct Node{
	double x, y, h;
}node[Max];
double mapp[Max][Max], dis[Max];
int vis[Max];
int n;
double dist(Node a,Node b){
	double x = (a.x - b.x) * (a.x - b.x);
	double y = (a.y - b.y) * (a.y - b.y);
	double h = (a.h - b.h) * (a.h - b.h);
	return sqrt((x+y)*1.0) + h; 
}
double prim(){
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	for(int i = 1; i <= n; i++){
		dis[i] = mapp[1][i];
	} 
	dis[1] = 0;
	vis[1] = 1;
	double ans = 0;
	for(int i = 2; i <= n; i++){
		double minn = inf*1.0;
		int k = -1;
		for(int j = 1; j <= n; j++){
			if(!vis[j] && dis[j] < minn){
				minn = dis[j];
				k = j;
			}
		}
		vis[k] = 1;
		ans += minn;
		for(int v = 0; v < n; v ++){
			if(!vis[v] && dis[v] > mapp[k][v]){
				dis[v] = mapp[k][v];
			}
		}
	}return ans;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> node[i].x >> node[i].y >> node[i].h;
	}	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) mapp[i][j] = 0;
			else mapp[i][j] = inf;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			mapp[i][j] = mapp[j][i] = min(mapp[i][j], dist(node[i], node[j]));
		}
	}
	double ans = prim();
	cout << fixed << setprecision(2) << ans << endl; 
	return 0;
}
