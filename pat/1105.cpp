#include <bits/stdc++.h>
#define Max 101
using namespace std;
int m, n;
int N;
int mapp[Max][Max], vis[Max][Max];
int a[Max*Max];
int cmp(int a, int b){
	return a > b;
}
int main(){
	memset(a, 0, sizeof(a));
	memset(vis, 0, sizeof(vis));
	memset(mapp, 0, sizeof(mapp));
	cin >> N;
	/*
	�ȼ�������m������n��ֵ��n�Ӹ���N���������ֿ�ʼ����ǰ��һֱ��1��
	�ҵ���һ������N % n== 0�ģ�m��ֵ����N/n
	*/
	for(n = sqrt(N); n >= 1; n--){
		if(N % n == 0){
			m = N / n;
			break;
		}
	}
//	cout << m << " " << n << endl;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N, cmp);

	int i = 0, j = 0, index = 0;
	while(true){
		int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0; 
		//�� 
		while( j < n ){
			if(!vis[i][j]){
				flag1 = 1;
				mapp[i][j] = a[index++];
				vis[i][j] = 1;
				j++;
			}else{
				break;
			}
		}
		j--;
		i++;
		//��
		while( i < m ){
			if(!vis[i][j]){
				flag2 = 1;
				mapp[i][j] = a[index++];
				vis[i][j] = 1;
				i++;
			}else break;
		} 
		i--;
		j--;
		//�� 
		while( j >= 0){
			if(!vis[i][j]){
				flag3 = 1;
				mapp[i][j] = a[index++];
				vis[i][j] = 1;
				j--;
			}else break;
		}
		j++;
		i--;
		//�� 
		while( i >= 0){
			if(!vis[i][j]){
				flag4 = 1;
				mapp[i][j] = a[index++];
				vis[i][j] = 1;
				i--;
			}else break;
		}
		i++;
		j++;
		if(!flag1&&!flag2&&!flag3&&!flag4){
			break;
		}
	} 
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << mapp[i][j];
			if(j != n - 1) {
				cout << " ";
			}
		}
		cout << endl;
	} 
	return 0;
}
