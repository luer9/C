#include <bits/stdc++.h>
#define Max 100005
using namespace std;
int n;
int a[Max];
int cmp(int a,int b){
	return a > b;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n, cmp);
	int ans = 1;
	for(int i = 0; i < n; i++){
		if(a[i] > ans){
			ans++;
		}else
			break;
	}
	cout << ans-1 << endl;
	return 0;
}
