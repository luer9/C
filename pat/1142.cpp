#include <bits/stdc++.h>
#define Max 202
using namespace std;
int mapp[Max][Max];
int n, m;
int u, v;
int q, k;
int vv[Max];
set<int > s;
int main(){
	ios::sync_with_stdio(false);
	memset(mapp, 0, sizeof(mapp));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		mapp[u][v] = mapp[v][u] = 1;
	}
	
	cin >> q;
	while(q--){
		cin >> k;
		s.clear();
		memset(vv, 0, sizeof(vv));
		for(int i = 1; i <= k; i++){
			cin >> vv[i];
			s.insert(vv[i]);
		}
		int flag = 0;
		for(int i = 1; i <= k; i++){
			for(int j = i+1 ; j <= k; j++){
				if(mapp[vv[i]][vv[j]] == 0) {
					flag = 1;
					break;
				}
			}
		} 
		if(flag == 1) cout << "Not a Clique" <<endl;
		else {
			for(int i = 1; i <= n; i++){
				if(s.count(i)) continue;
				else{
					int cnt = 0;
					int j;
					for(j = 1; j <= k; j++){
						if(mapp[i][vv[j]] ==0) break;
					}
					if(j == k+1){
						cout << "Not Maximal" << endl;
						flag = 2;
						break;
					}
				}
			}
			if(!flag) cout << "Yes" << endl;
		}
	}
	return 0;
}
