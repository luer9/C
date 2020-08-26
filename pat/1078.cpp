#include <bits/stdc++.h>
#define Max 10005
using namespace std;
int isprime(int a){
	if(a == 1) return 0;
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i ==0) return 0;
	}
	return 1;
}
int m, n;
int a[Max], vis[Max];
int main(){
	cin >> m >> n;
	while(!isprime(m)){
		m++;
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++){
		int flag = 0;
		for(int j = 0; j < m; j++){
			int pos = (a[i] + j * j) % m;
			if(!vis[pos]){
				vis[pos] = 1;
				flag = 1;
				cout << pos;
				break;
			}
		}
		if(!flag) cout << "-";
		if(i != n - 1) cout << " ";
	}
	cout << endl;
	return 0;
}
//(key + step * step) % size Æ½·½Ì½²â 
