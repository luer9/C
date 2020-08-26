/*
判断是否在一行或者是对角线 
*/
#include <bits/stdc++.h>
#define Max 1011 
using namespace std;
int row[Max]; //行
//int col[Max]; //列 
int k, n, flag;
int main(){
	cin >> k;
	while(k--){
		flag = 0;
		memset(row, 0, sizeof(row));
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> row[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(((j - i) == abs(row[j] - row[i]))||(row[j] == row[i])){
					flag = 1;
					break;
				}
			}
			if(flag){
				break;
			}
		} 
		if(flag){
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
