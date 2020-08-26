//两个集合的元素个数差最小的情况下，保证两个集合的差最大
//|n1-n2| 最小的情况 0,1 
#include <bits/stdc++.h>
#define Max 100015
using namespace std;
int a[Max], n; 
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n/2; i++){
		sum1 += a[i];
	}
	for(int i = n/2; i < n; i++){
		sum2 += a[i];
	}
	if(n%2 == 1){
		cout << 1 << " " << sum2 - sum1 << endl;
	}else cout << 0 << " " << sum2 - sum1 << endl;
	return 0;
}
