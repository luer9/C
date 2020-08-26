//连续子序列分割 
#include <bits/stdc++.h>
#define Max 100001
using namespace std;
int n, m;
int pre[Max], a[Max];
int main(){
	memset(pre, 0, sizeof(pre));
	int flag = 0, low = 0, minn = 0x3f3f3f;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i-1] + a[i]; //前缀和 
		while(pre[i] - pre[low] > m){
			minn = min(pre[i] - pre[low], minn);
			low++;
		}
		if(pre[i] - pre[low] == m){
			cout << low+1 << "-" << i << endl;
			flag = 1;
		}
	} 
	if(!flag){
		low = 0;
		for(int i = 1; i <= n; i++){
			while(pre[i] - pre[low] > minn){
				low++;
			}
			if(pre[i] - pre[low] == minn){
				cout << low+1 << "-" << i <<endl;
			}
		}
	}

	return 0;
}
