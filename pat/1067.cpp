#include <bits/stdc++.h>
#define Max 110005
using namespace std;
int n, a[Max];
int pos[Max];
int cnt, ans; 
int main(){
	memset(a, 0, sizeof(a));
	memset(pos, 0, sizeof(pos));
	ans = 0;
	cin >> n;
	cnt = n - 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		pos[a[i]] = i;
		if(a[i] == i && a[i] != 0) cnt--;//需要交换的 
	}
	int j = 1;
	while(cnt){
		if(pos[0] != 0){
			swap(pos[0], pos[pos[0]]);
			cnt--;
			ans++;
		}else{
			for(;j < n; j++){  //前边的顺序都安排好了 每次从 j 开始遍历 如果 每次 从头遍历 会超时 
				if(pos[j] != j){
					swap(pos[0], pos[j]);
					ans++;
					break;
				}
			}
		}
	} 
	cout << ans << endl;
	return 0;
}
