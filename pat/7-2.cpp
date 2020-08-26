#include <bits/stdc++.h>
#define Max 101
using namespace std;
int a[Max], b[Max];
int n;
int judge(){
	int ind = 0;
	for(int i = 1; i < n; i++){
		if(b[i-1] <= b[i]) continue;
		else {
			ind = i;
			break;
		}
	}
	for(int i = ind; i < n; i++){
		if(a[i] != b[i])
			return -1;
	}
	return ind;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int j = 0; j < n; j++) {
		cin >> b[j];
	}
	int res = judge();
	if(res != -1){
		cout <<"Insertion Sort"<< endl;
		sort(b, b + res + 1);
		for(int i = 0; i < n; i++){
			cout << b[i];
			if(i != n-1) cout << " ";
			else cout << endl; 
		}
	}else {
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1;
		while(flag){
			flag = 0;
			for(int i = 0; i < n; i++){
				if(a[i] != b[i])
					flag = 1;
			}
			k = k * 2;
			for(int i = 0; i < n/k; i++){
				sort(a + i*k, a + (i+1)*k);
			}
			sort(a + n/k*k, a+n);
		}
		for(int i = 0; i < n; i++){
			cout << a[i];
			if(i != n - 1) {
				cout << " ";
			}else cout << endl;
		}
	}
	return 0;
}
