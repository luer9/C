#include <bits/stdc++.h>
#define Max 11000
using namespace std;
struct Peo{
	string name;
	int h;
}peo[Max];
int n, k;
int cmp (Peo a,Peo b){
	if(a.h == b.h){
		return a.name < b.name;
	}
	return a.h > b.h;
}
void print(int index, int n){
	int a[n];
	a[n/2] = index;
	int left = n/2 - 1, right = n/2 + 1, i = index+1;
	while(left >= 0 || right < n){
		if(left >= 0) a[left--] = i++;
		if(right < n) a[right++] = i++;
	}
	for(int i = 0; i < n; i++){
		cout << peo[a[i]].name;
		if(i != n - 1) cout << " ";
	}
	cout << endl;
} 
void solve(int n, int k){
	sort(peo, peo+n, cmp);
	int num = n/k;
	print(0, num + n%k);
	for(int i = num + n%k; i < n; i+=num){
		print(i, num);
	}
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> peo[i].name >> peo[i].h;
	}
	solve(n, k);
	return 0;
}
