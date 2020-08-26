//把螺旋矩阵搞出来 
#include <bits/stdc++.h>
#define Max 1002
using namespace std;
int n, m;
int r, c;
int mapp[Max][Max];
int main(){
	memset(mapp, 0, sizeof(mapp));
	cin >> n >> m;
	cin >> r >> c;
	int i = 1, j = 1, num = 1;
	while(true){
		int flag = 0;
		//右
		while( j <= m && mapp[i][j] == 0){
			flag = 1;
			mapp[i][j] = num ++;
			j++;
		} 
		j--;
		i++;
//		cout << "-> "<< i <<"  " << j << endl;
		//下
		while( i <= n && mapp[i][j] == 0){
			flag = 1;
			mapp[i][j] = num ++;
			i++;
		}
		i--;
		j--;
//			cout << "--> "<< i <<"  " << j << endl;
		//左
		while( j >= 1 && mapp[i][j] == 0){
			flag = 1;
			mapp[i][j] = num ++;
			j --;
		} 
		j++;
		i--;
//			cout << "---> "<< i <<"  " << j << endl;
		//上 
		while( i >= 1 && mapp[i][j] == 0){
			flag = 1;
			mapp[i][j] = num ++;
			i--;
		}
		i++;
		j++;
//			cout << "----> "<< i <<"  " << j << endl;
		if(flag == 0) break;
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout << mapp[i][j] << "\t";
//		}
//		cout << endl;
//	}
	cout << mapp[r][c] << endl;
	return 0;
} 
