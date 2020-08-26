#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[33][33], b[33][33], c[33][33];
ll temp[33][33];
int n, m; 
int main(){
//#ifdef ONLINE_JUDGE
//#else
//	freopen("input1.txt","r",stdin);
//#endif 
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	memset(temp, 0, sizeof(temp)); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	} 
	if(m == 0){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if( i == j) {
					a[i][j] = 1;
				}else a[i][j] = 0;
			}
		} 
	}else{
		for(int l = 1; l < m; l++){
			for(int k = 1; k <= n; k++){
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++){
						temp[k][i] += a[k][j] * b[j][i];
					}
				}
			}
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					a[i][j] = temp[i][j];
					temp[i][j] = 0;
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j]; 
			if(j == n){
				cout << endl;
			}else cout << " ";
		}
	}
	return 0;
}
/*
10 4
4 3 6 0 5 2 5 0 1 3 
1 5 1 0 7 1 4 9 6 0 
5 0 9 0 2 0 6 0 9 5 
2 1 4 1 5 0 0 1 5 3 
0 3 0 0 9 9 4 9 3 3 
0 6 8 9 7 5 0 8 5 4 
4 4 2 5 9 9 0 7 9 5 
4 1 7 3 2 4 3 0 3 1 
0 5 3 8 7 7 3 3 1 7 
6 6 5 4 0 9 3 5 8 3 
*/
