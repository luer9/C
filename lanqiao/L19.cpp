#include <bits/stdc++.h>
#define Max 101
using namespace std;
int sticks[Max],vis[Max];
int min_len; // 满足条件的最小长度
int stick_num;//  木棍数量 
int n;// stick的数量
int total_len; // 木棍总长度
int cmp ( int a, int b){
	return a > b;
} 
/*
	sum 指当前拼凑的这根木棍的长度
	cur 指当前正在搜索的木棍下标 
	res 表示已经拼成的木棍的数量
	k 表示假设的单个木棍的长度   ->  min_len 
*/
bool dfs(int sum, int cur, int res, int k){
	if(res == stick_num){
		return true;
	}
	for(int i = cur; i < n; i++){
		//第i个被用了，或者与前一个木棍长度相同但是 前一个也没被用 
		//那么 这个也不能被用 
		if(vis[i] || (i && sticks[i] == sticks[i-1] && !vis[i-1])){
			continue;
		}
		if(sticks[i] + sum == k) {
			vis[i] = 1;
			if(dfs(0, 0, res+1, k)){
				return true;
			}
			vis[i] = 0; //虽然这步拼成了长度为x的木棍，但是剩下的不能成功拼凑，所以失败回溯 
			return false;
		}
		if(sticks[i] + sum < k) { //没拼好 
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
		//从大到小排序  可以在比较少的次数里合成想要的那种长度 
		sort(sticks, sticks + n, cmp);
		int flag = 0;
		for(min_len = sticks[0]; min_len < total_len; min_len++){
			//因为初始的木棍是等长的 
			if(total_len % min_len == 0) {
				memset(vis, 0, sizeof(vis));
				stick_num = total_len / min_len; // 可能的最多木棍数量 
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
