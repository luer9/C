#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt = 0;
	for(int i = 1; i <= 1200000; i++){
		if(1200000 % i == 0) {
//			cout << i << endl;
			cnt++;
			cout << "-->" << i << " " << cnt << endl; 
		} 
	}
	return 0;
} 
// 96
