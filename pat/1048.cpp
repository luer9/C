#include <bits/stdc++.h>
using namespace std;
int n, m;
int val;
int flag[1001];
int main(){
	memset(flag, 0, sizeof(flag));
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> val;
		flag[val]++;
	} 
	int flag1 = 0;
	for(int i = 1; i <= m/2; i++){
		if(flag[i] && flag[m-i] && i != m - i){
			flag[i]--; flag[m-i]--;
			cout << i << " " <<m - i <<endl;
			flag1 = 1;
			break; 
		}else if(flag[i] >=2 && i == m - i){
			flag1 = 1;
			flag[i]--; flag[i]--;
			cout << i <<" " << m - i << endl;
			break;
		}
	}
	if(!flag1) cout << "No Solution" << endl;
	return 0;
}
