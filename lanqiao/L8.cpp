#include <bits/stdc++.h>
using namespace std;
int n;// �ʺ���Ŀ
int mapp[10][10];
int white[10], black[10]; //  white[i] ��i���ʺ���� white��
int ans = 0;  //�� 
//pos �д������ڷŵ� pos+1 ���ʺ� 
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
	
	//��һ��λ����֮ǰλ�� �жϺ��� ������ 
	for(int i = 0; i < pos-1 ; i++){
		int judge = white[pos-1] - white[i];
		//ͬһ�л��� �Խ��� (�ж�����֮�����ֵ�Ƿ����) 
		if(judge == 0 || abs(judge) == (pos - 1 - i) ){
			return ;
		}
	}
	//�׷��� ��ʼ�źڻʺ� 
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
