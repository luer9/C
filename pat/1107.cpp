#include <bits/stdc++.h>
#define Max 1005
using namespace std;
int pre[Max], hobby[Max], num[Max];
int n, k, h;
void init(){
	memset(hobby, -1, sizeof(hobby));
	memset(num, 0, sizeof(num));
	for(int i = 0; i <= n; i++)
		pre[i] = i;
}
int find(int x){
	if(pre[x] == x) return x;
	else return pre[x] = find(pre[x]);
}
int mix(int a, int b){
	int fa = find(a);
	int fb = find(b);
	if(fa!=fb) pre[fa] = fb;
}
int cmp(int a, int b){
	return a > b;
}
int main(){
	cin >> n;
	init();
	for(int i = 1; i <= n; i++){
		cin >> k;
		scanf(":");
		for(int j = 0; j < k; j++){
			cin >> h;
			if(hobby[h] == -1) hobby[h] = i;
			else mix(hobby[h], i);
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		int fa = find(i);
		if(fa == i){
			cnt ++;
		}
		num[fa] ++;
	}
	sort(num+1, num+1+n, cmp);
	cout << cnt << endl;
	for(int i = 1; i <= n; i++){
		if(num[i] == 0) break;
		if(i == 1) cout << num[i];
		else cout << " " << num[i];
	}
	cout << endl;
	return 0;
}
