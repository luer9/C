#include <bits/stdc++.h>
#define Max 10002
using namespace std;
map<string,int> vis;
map<string,string> mapp;
int n, m;
string peo[Max];
string a, b;
int main() {
	mapp.clear();
	vis.clear();
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		mapp[a] = b;
		mapp[b] = a;
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> peo[i];
		vis[peo[i]] = 1;
	}
	set <string> s;
	s.clear();
	for(int i = 0; i < m; i++) {
		if(vis[mapp[peo[i]]] == 1) {
			continue;
		}
		s.insert(peo[i]);
	}
	cout << s.size() << endl;
	int flag = 0;
	set<string> :: iterator it;
	for(it = s.begin(); it != s.end(); it++){
		if(!flag) {
			cout << (*it); flag = 1;
		}else {
			cout << " " << (*it) ;
		}
	} 
	
	return 0;
}
