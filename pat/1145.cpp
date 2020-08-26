#include <bits/stdc++.h>
#define Max 11000
int n, m, msize, table[Max];
using namespace std;
int isPrime(int a) {
	if( a == 1 || a == 0) return 0;
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0) return 0;
	} 
	return 1;
}
int Hash(int k,int Tsize){
	return k % Tsize;
}
int main(){
	
	int a;
	memset(table, -1 , sizeof(table));
	cin >> msize >> n >> m;
	//如果给定的TSize是合数，则要重置为离这个数最近的比它大的素数
	while(isPrime(msize) == 0) msize++;
	for(int i = 0; i < n; i++){
		cin >> a;
		int founded = 0;
		for(int j = 0; j < msize; j++){
			int d = j * j; // 处理冲突 ， 二次方 探测再散列……数据结构讲过 
			int tid = (Hash(a,msize) + d) % msize;
			if(table[tid] == -1) {
				founded = 1;
				table[tid] = a;
				break;
			}
		}
		if(founded == 0){
			cout << a << " cannot be inserted." << endl;
		}
	}
	int tot = 0;
	for(int i = 0; i < m; i++){
		cin >> a;
		int t = 0;
		int founded = 0;
		for(int j = 0; j < msize; j++){
			tot ++;
			int d = j * j;
			int tid = (Hash(a, msize) + d) %msize;
			if(table[tid] == a || table[tid] == -1){
				founded = 1;
				break;
			}
		}
		if(founded == 0) {
			tot++;
		}
	}
	cout << fixed << setprecision(1) << tot*1.0/m << endl;
	
	return 0;
}
