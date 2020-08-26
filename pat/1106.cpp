#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define Max 100005 
using namespace std;
int n, k, id;
double p, r;
vector <int> vec[Max];
int min_dept = inf, ans = 1;
void dfs(int index, int dept){
	if(min_dept < dept){
		return ;
	}
	if(vec[index].size() == 0) {
		if(min_dept == dept){
			ans++;
		}else if(min_dept > dept){
			min_dept = dept;
			ans = 1;
		}
	}
	for(int i = 0; i < vec[index].size(); i++){
		dfs(vec[index][i], dept +1);
	}
}
int main(){
	cin >> n >> p >> r;
	for(int i = 0; i < n; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> id;
			vec[i].push_back(id);
		}
	}
	dfs(0, 0);
	cout << fixed << setprecision(4) << p * pow(1 + r/100, min_dept) <<" " << ans << endl;
	return 0;
	return 0;
}
