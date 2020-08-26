#include <bits/stdc++.h>
using namespace std;
int n, k;
int u, v;
string nam;
vector<string> vec[3005];
int main(){
	scanf("%d%d", &n, &k); 
	for(int i = 0; i < n; i++){
		cin >> nam;
		scanf("%d",&u);
		for(int j = 0; j < u; j++){
			scanf("%d",&v);
			vec[v].push_back(nam);
		}
	}
	for(int i = 1; i <= k; i++){
		printf("%d %d\n",i, vec[i].size());
		sort(vec[i].begin(),vec[i].end());
		for(int j = 0; j < vec[i].size(); j++){
			printf("%s\n",vec[i][j].c_str());
		}
	}
	return 0;
}
