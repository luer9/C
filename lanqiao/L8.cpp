#include <bits/stdc++.h>
using namespace std;
int n;// 皇后数目
int mapp[10][10];
int white[10], black[10]; //  white[i] 第i个皇后放在 white列
int ans = 0;  //答案 
//pos 行代表正在放第 pos+1 个皇后 
void solve_black(int pos){
	
	for(int i = 0; i < pos-1; i++) {
		int judge = black[pos-1] - black[i];
		if(judge == 0 || abs(judge) == (pos - 1 - i)) {
			return ;
		} 
	}
	if(pos == n) {
		ans ++;
		return ;
	}
	
	for(int i = 0; i < n; i++){
		if(mapp[pos][i] && white[pos] != i) {
			black[pos] = i;
			solve_black(pos+1);
		} 
	} 
} 
void solve_white(int pos){
	
	//上一个位置与之前位置 判断合理 不合理 
	for(int i = 0; i < pos-1 ; i++){
		int judge = white[pos-1] - white[i];
		//同一列或者 对角线 (判断行列之差绝对值是否相等) 
		if(judge == 0 || abs(judge) == (pos - 1 - i) ){
			return ;
		}
	}
	//白放完 开始放黑皇后 
	if(pos == n) {
		solve_black(0);
		return ;		
	} 
	for(int i = 0; i < n; i++) {
		if(mapp[pos][i]){
			white[pos] = i;
			solve_white(pos+1);
		}
	}
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> mapp[i][j];
		}
	} 
	solve_white(0);
	cout << ans << endl;
	return 0;
}
