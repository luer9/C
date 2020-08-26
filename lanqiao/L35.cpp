#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int a[11000], n;
//检查左边有没有比它小的 
int check_left(int i){
	for(int j = 1; j < i; j++){
		if(a[j] < a[i]){
			return 1;
		}
	}
	return 0;
}
//检查右边有没有比它大的
int check_right(int i){
	for(int j = i + 1; j <= n; j++){
		if(a[j] > a[i]) {
			return 1;
		}
	}
	return 0;
} 
int main(){
	memset(a, 0, sizeof(a));
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 2; i < n; i++){
		if(check_left(i) && check_right(i)){
//			cout << i << " " << a[i] << " :: " << endl; 
			cnt ++;
		}
	}
	cout << cnt << endl;
	return 0;
}
