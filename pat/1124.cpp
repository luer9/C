#include<bits/stdc++.h>
using namespace std;
int m, n, s;
map<string,int> vis;
string name[1100];
int main(){
	vis.clear();
	cin >> m >> n >> s;
	for(int i = 1; i <= m; i++) {
		cin >> name[i];
	}
	int flag = 0;
	for(int i = s; i <= m; ) {
		if(!vis[name[i]]){
			flag = 1;
			cout << name[i] << endl;
			vis[name[i]] = 1;
			i += n; 
		}else {
			i++;
		}
	}
	if(!flag) {
		cout << "Keep going..." << endl;
	}
	return 0;
} 
