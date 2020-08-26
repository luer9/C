#include <bits/stdc++.h>
using namespace std;
map<int,int> vis;
int n, a;
int main(){
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		vis[a] = 1;
	} 
	for(int i = 1;; i++){
		if(!vis[i]){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
} 
