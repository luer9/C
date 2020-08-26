#include <bits/stdc++.h>
#define Max 1002
#define ll long long
using namespace std;
struct circle{
	int x, y, r;
	int area;
}c[Max];
int vis[Max];
int n;
//没有开根号 
int dis(circle a, circle b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int cmp(circle a, circle b){
	return a.area > b.area;
}
bool check(circle cir, int pos){
	for(int i = 0; i < pos; i++){
		if(vis[i]){
			if((c[i].r + cir.r)*(c[i].r + cir.r) < dis(c[i], cir)){
				return false;
			}
		}
	}
	return true;
} 
int main(){
	memset(vis, 0, sizeof(vis));
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> c[i].x >> c[i].y >> c[i].r;
		c[i].area = c[i].r * c[i].r; 
	}
	ll ans = 0;
	ans += c[0].area; vis[0] = 1;
	for(int i = 1; i < n; i++){
		if(check(c[i], i)){
			ans +=  c[i].area;
		}
	}
	cout << ans << endl;
	return 0;
} 
