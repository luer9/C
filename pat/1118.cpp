#include <bits/stdc++.h>
#define Max 10001
using namespace std;
int n, k, q, b, b0;
int fa[Max], vis[Max];
int Find(int a){
	return a == fa[a]? a : fa[a] = Find(fa[a]);
}
void mix(int a, int b){
	int Fa = Find(a);
	int Fb = Find(b);
	if(Fa != Fb){
		fa[Fa] = Fb;	
	}
}
void init(){
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < Max; i++){
		fa[i] = i;
	}
}
int main(){
	ios::sync_with_stdio(false);
	init();
	int maxx = -1;
	cin >> n;
	for(int i = 0; i < n; i++){
		 cin >> k;
		 cin >> b0;
		 vis[b0] = 1;
		 if(b0 > maxx) maxx = b0;
		 for(int j = 1; j < k; j++){
		 	cin >> b;
		 	vis[b] = 1;
		 	if(b > maxx) maxx = b;
		 	mix(b, b0);
		 }
	}
	int cnt = 0;
	for(int i = 1; i <= maxx; i++){
		if(Find(i) == i && vis[i]){
			cnt++;
		}
	}
	cout << cnt << " " << maxx << endl;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		if(Find(a) == Find(b)){
			cout << "Yes" << endl;
		}else cout << "No" << endl;
	}
	return 0;
}
