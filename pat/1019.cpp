#include <bits/stdc++.h>
#define Max 1001
#define ll long long
ll n,b;
using namespace std;
int a[Max], ind;
int change(ll n, ll b) {
	memset(a, 0, sizeof(a)); 
	while (n) {
		int c = n % b;
		a[ind++] = c;
		n = n / b;
	}
	int flag = 0;
	for(int i = 0; i < ind/2; i++) {
		if(a[i] != a[ind - i -1]) flag = 1;
	}
	if(flag) return 0;
	else return 1;
}
int main() {
	cin >> n >> b;
	int flag = change(n, b);
	if(flag){
		cout << "Yes" << endl;
	}else cout << "No" << endl;
	for (int i = ind - 1;i >= 0; i--) {
		cout << a[i];
		if(i!=0) cout << " ";
	}
	if(n == 0) cout << "0" << endl;
	cout << endl;
	return 0;
}
