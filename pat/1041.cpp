#include <bits/stdc++.h>
#define Max 100050 
using namespace std;
int n;
int a[Max], cnt[Max];
int main() {
	memset(a, 0, sizeof(a)); 
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (int i = 0;i < n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if(cnt[a[i]] == 1) {
			cout << a[i] << endl;
			flag = 1;
			break;
		}
	}
	if (!flag) cout << "None" << endl;
	return 0;
}
