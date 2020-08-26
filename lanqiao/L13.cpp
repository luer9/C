#include <iostream>
using namespace std;
int n;
int a[25][25];
bool vis[25];
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int j = 1; j <= n; ++j) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (i != j) {
				if (a[i][j] == 0) {
					cnt++;
				}
			}
		}
		if (cnt >= (n + 1)/2) {
			vis[j] = true;
		} 
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i])
			cout << i << " ";
	}
	return 0;
}
