//≤ªª·–¥ 
#include <bits/stdc++.h>
#define ll long long 
#define Mod 10000
using namespace std;
int m, n;
ll ans = 0;
int main(){
	cin >> m >> n;
	if(m == 3) {
		for(int i = 1; i <= n; i++){
			ans += (n-i) * (n-i);
		}
	}
	cout << ans % Mod << endl;
	return 0;
} 
