#include <bits/stdc++.h>
#define Max 100050
using namespace std;
int n, a[Max];
int vis[Max];
int sum (int num){
	int sum = 0;
	while(num){
		int c = num % 10;
		sum += c;
		num /= 10; 
	}
	return sum;
}
int main(){
	int ans[Max]={0}, index = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
//		cout << sum(a[i]) << " " << a[i] << endl;

		if(!vis[sum(a[i])]){
			ans[index++] = sum(a[i]);
		}
		vis[sum(a[i])] = 1;
	
	}
	sort(ans, ans+index);
	cout << index << endl;
	int i;
//	for(i = 0; i < index; i++){
////		cout <<" * "<< ans[i] << " " << vis[ans[i]] << endl; 
//		if(vis[ans[i]]) {
//			cout << ans[i];
//			break;
//		}
//	}
	for(i = 0; i < index; i++){
		cout << ans[i];
		if(i!=index - 1) {
			cout << " ";
		} 
	}
//	cout << endl;
	return 0;
}
