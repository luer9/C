#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define Max 100005
#define ll long long
using namespace std;
int n, m;
ll a[Max], b[Max];
int vis[Max];
int cmp(int a,int b){
	return a > b;
}
int main(){
	memset(vis, 0, sizeof(vis));
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}	
	sort(b, b+n, cmp);
	for(int i = 0; i < m; i++){
		vis[b[i]] ++;
	}
	int cnt = m;
	for(int i = 0; i < n; i++){
		if(vis[a[i]]){
			cout << a[i];
			vis[a[i]] --;
			cnt --;
			if(cnt == 0) cout << endl;
			else cout << " ";	
		}
	}
	return 0;
} 
