#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define Max 202 
using namespace std;
struct Node{
	string name;
	int happ; 
}city[Max];
map<string, int> map1;
int mapp[Max][Max]; ///��ͼ
int dis[Max]; //ԭ�㵽i��cost
int h[Max]; //ԭ�㵽i�� happiness
int num[Max]; // ԭ�㵽 i �����ĳ�������
int route[Max]; // ���·������
int pre[Max]; // i��ǰ���ڵ�
int vis[Max]; // cityi�Ƿ񱻾��� 
string name, u, v;
int n, k, c; 
void dijkstra(int st){
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	dis[st] = 0; h[st] = 0; num[st] = 1; pre[st] = 0; route[st] = 1;
	for(int i = 0; i < n; i++){
		int u = -1, minn = inf;
		for(int j = 0; j < n; j++){
			if(!vis[j] && dis[j] < minn){
				minn = dis[j];
				u = j;
			}
		}
		if(u == -1) break;
		vis[u] = 1;
		for(int v = 0; v < n; v++){
			if(!vis[v] && mapp[u][v] < inf){
				//�ҵ����·������ 
				if(dis[v] > dis[u] + mapp[u][v]){ 
					dis[v] = dis[u] + mapp[u][v];
					route[v] = route[u];
					h[v] = h[u] + city[v].happ;
					num[v] = num[u] + 1;
					pre[v] = u;
				}else if(dis[v] == dis[u] + mapp[u][v]){
					route[v] += route[u];
					if(h[v] < h[u] + city[v].happ){ //·����ͬ ����ֵ���� ���� 
						h[v] = h[u] + city[v].happ;
						num[v] = num[u] + 1;
						pre[v] = u;
					}else if(h[v] == h[u] + city[v].happ){ //·����ͬ ����ֵ��ͬ �����������ٵ� ƽ������ֵ�� ���� 
						if(num[v] > num[u] + 1){
							num[v] = num[u] + 1;
							pre[v] = u;	
						}
					}
				}
			}
		}
	}
}
void dfs(int v){
	if(v == 0) {
		cout << city[v].name;
		return ;
	}
	dfs(pre[v]);
	cout << "->" << city[v].name;
}
int main(){
	memset(mapp, inf, sizeof(mapp));
	cin >> n >> k;
	cin >> name;
	map1[name] = 0;
	city[0].name = name; 
	for(int i = 1; i < n; i++){
		cin >> city[i].name >> city[i].happ;
		map1[city[i].name] = i;
	}
	for(int i = 0; i < k; i++){
		cin >> u >> v >> c;
		mapp[map1[u]][map1[v]] = mapp[map1[v]][map1[u]] = c;
	}
	dijkstra(0);
	int end = map1["ROM"];
	//���·������  ���·��  �����ֵ  ƽ������ֵ��������㣩 
	cout << route[end] << " " << dis[end] << " " << h[end] << " " << h[end] / (num[end] - 1) << endl;
	dfs(end);
	return 0;
}
