#include <bits/stdc++.h>
#define Max 100001
using namespace std;
int n, m;
int pre[Max];
int bsearch(int low, int high, int key){
	int l = low, r = high;
	if(pre[r] <= key){
		return r + 1; 
	}
	while(l < r){
		int mid = (l + r) >> 1;
		if(pre[mid] > x) {
			r = mid;
		}else l = mid + 1;
	}
	return l;
}
int main(){
	memset(pre, 0, sizeof(pre));
	int flag = 0, low = 0, minn = 0x3f3f3f;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> pre[i];
		pre[i] += pre[i - 1]; 
	}
	for(int i = 1; i <= n; i++){
		int pos = bsearch(i, n, pre[i - 1] + m);
		if(pre[pos - 1] - pre[i - 1] == m){
			minn = m;break;
		} 
		else if(pre[pos] - pre[i - 1] > m && pre[pos] - pre[i - 1] < minn){
			minn = pre[pos] - pre[i - 1]; 
		}
	
	}
	for(int i = 1; i <= n; i++){
		int pos = bsearch(i, n, sum[i - 1] + minn);
		if()
	} 
	return 0;
	
} 
