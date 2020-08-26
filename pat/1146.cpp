#include <bits/stdc++.h>
#define Max 1111
using namespace std;
int n, m, k;
int u, v;
vector<int> vec[Max];
int in[Max];
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		vec[u].push_back(v);
		in[v]++;
	}
	int flag = 0;
	cin >> k;
	for(int i = 0; i < k; i++) {

		int judge = 1;
		vector<int> tempIn(in, in + n + 1);
		for(int j = 0; j < n; j++) {
			cin >> u;
			if(tempIn[u] != 0) judge = 0; //不是拓扑序列
//			for(int it : v[u]) tempIn[it] --;
			for(int it = 0; it < vec[u].size(); it++) {
				tempIn[vec[u][it]] --;
			}
		}
		if(judge == 1) continue; //是拓扑序列
		if(!flag) {
			cout << i;
			flag = 1;
		} else {
			cout << " " << i;
		}
	}
	cout << endl;
	return 0;
}
