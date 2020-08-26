#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define Max 11000
using namespace std;
struct Node{
	int to, val;
	Node(){}
	Node(int a,int b){
		to = a;
		val = b;
	}
};
int n;
int dis[Max];
vector<Node> vec[Max];
bool vis[Max];
void dfs(int u){
	for(int i = 0; i < vec[u].size(); i++){
		Node v = vec[u][i]; 
		int to = v.to;
		int val = v.val;
		if(!vis[to]){
			vis[to] = 1;
			dis[to] = dis[u] + val;
			dfs(to);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int u,v,val;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v >> val;
		vec[u].push_back(Node(v, val));
		vec[v].push_back(Node(u, val));
	}
	//第一次dfs 
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	vis[1] = 1;
	dfs(1);
	int temp = -1, end;
	for(int i = 1; i <= n; i++){
		if(dis[i] > temp){
			temp = dis[i];
			end = i;
		}
	}
	//第二次dfs 
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	vis[end] = 1;
	dfs(end);
	temp = -1;
	for(int i = 1; i <= n; i++){
		if(dis[i] > temp) temp = dis[i];
	}
	cout << 10*temp + (temp+1)*temp / 2 << endl; // 等差数列求和 
	return 0;
} 
