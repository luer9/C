#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[22], ind, len;
string s;
int cnt[22];
void mutiply() {
	for (int i = 1; i <= len; i++) {
		a[i] = a[i] * 2;
	}
	for (int i = 1; i <= len; i++) {
		int jw = a[i] / 10;
		int ys = a[i] % 10;
		a[i] = ys;
		a[i-1] += jw;
	}
}
int main() {
	memset(a, 0, sizeof(a));
	memset(cnt, 0, sizeof(cnt));
	ind = 0;
	cin >> s;
	len = s.length();
	for(int i = 0; i < len; i++) {
		a[i+1] = s[i]-'0';
	}
	for(int i = 1; i <= len; i++) {
		cnt[a[i]] ++;
	}
	mutiply();
	int flag = 0;
	if (a[0] == 0) {
		flag = 1;//Ã»½øÎ»
	}
	// for (int i = 0; i <= len; i++) {
	// 	cout << a[i] << endl;
	// }
	int flag1 = 0;
	if(flag) {
		for (int i = 1; i <= len; i++) {
			cnt[a[i]] ++;
		}
		for (int i = 1; i <= len; i++) {
			if(cnt[a[i]]%2 != 0) {
				flag1 = 1;
			}
		}
		if (flag1) {
			cout << "No" << endl;
			for (int i = 1; i <= len; i++) {
				cout << a[i] ;
			}
		}else {
			cout << "Yes" << endl;
			for (int i = 1; i <= len; i++) {
				cout << a[i];
			}
		}
	}else {
		for (int i = 0; i <= len; i++) {
			cnt[a[i]] ++;
		}
		for (int i = 0; i <= len; i++) {
			if(cnt[a[i]]%2 != 0) {
				flag1 = 1;
			}
		}
		if (flag1) {
			cout << "No" << endl;
			for (int i = 0; i <= len; i++) {
				cout << a[i] ;
			}
		}else {
			cout << "Yes" << endl;
			for (int i = 0; i <= len; i++) {
				cout << a[i];
			}
		}
	}

	return 0;
}
