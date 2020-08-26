#include <bits/stdc++.h>
using namespace std;
int n, m, k, q, u, v;
set<int> s[55];
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m;
		for(int j = 1; j <= m; j++){
			cin >> k;
			s[i].insert(k);	
		}
	}
	set <int>::iterator it;
	int same = 0, total = 0; 
	cin >> q;
	for(int i = 0; i < q; i++){
		same = 0; total = 0;
		cin >> u >> v;
		for(it = s[u].begin(); it != s[u].end(); it++){
			if(s[v].find((*it)) == s[v].end()){
				continue;
			}
			same++;
		}
		total = s[u].size() + s[v].size() - same;
		cout << fixed << setprecision(1) << same*1.0 / total*1.0 * 100 << "%" << endl;
	}
	return 0;
}
