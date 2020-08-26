#include <bits/stdc++.h>
#define Max 10002
using namespace std;
int main(){
	int n, a[Max];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n); // min -> max
	// 1 3 4 10 12 13 15 15
	double ans = 0, c;
	ans = (a[0] + a[1])/2.0;
	for(int i = 2; i < n; i++){
		ans = (ans + a[i])/2.0;
	}
	cout << floor(ans) << endl;
	return 0;
}
/*
15 15 13 12 10 4 3 1
*/ 
