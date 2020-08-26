#include <bits/stdc++.h>
#define Max 101
using namespace std;
int sticks[Max],vis[Max];
int min_len; // ������������С����
int stick_num;//  ľ������ 
int n;// stick������
int total_len; // ľ���ܳ���
int cmp ( int a, int b){
	return a > b;
} 
/*
	sum ָ��ǰƴ�յ����ľ���ĳ���
	cur ָ��ǰ����������ľ���±� 
	res ��ʾ�Ѿ�ƴ�ɵ�ľ��������
	k ��ʾ����ĵ���ľ���ĳ���   ->  min_len 
*/
bool dfs(int sum, int cur, int res, int k){
	if(res == stick_num){
		return true;
	}
	for(int i = cur; i < n; i++){
		//��i�������ˣ�������ǰһ��ľ��������ͬ���� ǰһ��Ҳû���� 
		//��ô ���Ҳ���ܱ��� 
		if(vis[i] || (i && sticks[i] == sticks[i-1] && !vis[i-1])){
			continue;
		}
		if(sticks[i] + sum == k) {
			vis[i] = 1;
			if(dfs(0, 0, res+1, k)){
				return true;
			}
			vis[i] = 0; //��Ȼ�ⲽƴ���˳���Ϊx��ľ��������ʣ�µĲ��ܳɹ�ƴ�գ�����ʧ�ܻ��� 
			return false;
		}
		if(sticks[i] + sum < k) { //ûƴ�� 
			vis[i] = 1;
			if(dfs(sticks[i] + sum, i + 1, res, k)){
				return true;
			}
			vis[i] = 0;
			if(!sum) return false;
		}
	}
	return false;
} 
int main(){
	while(cin >> n && n) {
		total_len = 0;
		for(int i = 0; i < n; i++) {
			cin >> sticks[i];
			total_len += sticks[i];
		}
		//�Ӵ�С����  �����ڱȽ��ٵĴ�����ϳ���Ҫ�����ֳ��� 
		sort(sticks, sticks + n, cmp);
		int flag = 0;
		for(min_len = sticks[0]; min_len < total_len; min_len++){
			//��Ϊ��ʼ��ľ���ǵȳ��� 
			if(total_len % min_len == 0) {
				memset(vis, 0, sizeof(vis));
				stick_num = total_len / min_len; // ���ܵ����ľ������ 
				if(dfs(0,0,0,min_len)){
					cout << min_len << endl;
					flag =  1;
					break;
				}
			}
		} 
		if(!flag) {
			cout << total_len << endl;
		}
	}
	return 0;
}
