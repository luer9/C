#include <iostream>
#include <cstring>
#include <string> 
using namespace std;
int n, m, k;
string mapp[1001];
int vis[1001][1001]; //标记着是不是新建的g 
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0 ; i < n; i++){
//		for(int j = 0; j < m; j++){
			cin >> mapp[i];
//		} 
	}
	cin >> k;
	for(int cnt = 0; cnt < k; cnt++){
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mapp[i][j] == 'g' && !vis[i][j]){
					//上
					if(i-1 >= 0 && mapp[i-1][j] == '.'){
						mapp[i-1][j] = 'g';	
						vis[i-1][j] = 1;
					}
					//下
					if(i+1 < n && mapp[i+1][j] == '.') {
						mapp[i+1][j] = 'g';
						vis[i+1][j] = 1;
					}
					//左
					if(j-1 >= 0 && mapp[i][j-1] == '.'){
						mapp[i][j-1] = 'g';
						vis[i][j-1] = 1;
					}
					//右 
					if(j+1 < m && mapp[i][j+1] == '.'){
						mapp[i][j+1] = 'g';
						vis[i][j+1] = 1;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << mapp[i][j];
		}
		cout << endl;
	}
	return 0;
}
