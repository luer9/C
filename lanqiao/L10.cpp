#include <bits/stdc++.h>
#define Max 202
using namespace std;
int n, m;
int index;
int mapp[Max][Max];
int vis[Max][Max];
int ans[Max*Max];
int main(){
	
	memset(vis, 0, sizeof(vis));
	memset(mapp, 0, sizeof(mapp));
	memset(ans, 0, sizeof(ans));
	index = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> mapp[i][j];
		}
	}

	int i = 0, j = 0, flag = 0;
	while(index < n*m){
		
		//об 
		while(i < n && !vis[i][j]){
			ans[index++] = mapp[i][j];
			vis[i][j] = 1;
			i++;
//			cout << "****" << endl;
		}

		i--;
		j++; 
		//ср 
		while(j < m && !vis[i][j]){
			ans[index++] = mapp[i][j];
			vis[i][j] = 1;
			j++;
		}
		j--;
		i--;
		//ио 
		while(i >= 0 && !vis[i][j]){
			ans[index++] = mapp[i][j];
			vis[i][j] = 1;
			i--;
		}
		i++;
		j--; 
		//вС 
		while(j >= 0 && !vis[i][j]){
			ans[index++] = mapp[i][j];
			vis[i][j] = 1;
			j--;
		}
		i++;
		j++;
		//xia 
	}
	for(int i = 0; i < index; i++) {
		cout << ans[i]; 
		if(i != index - 1) {
			cout << " ";
		}else cout << endl;
	}
}
