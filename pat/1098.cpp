#include <bits/stdc++.h>
using namespace std;
int n;
int a[101], b[101];
void downJust(int i, int n) {
	int j = 2 * i;
	while(j <= n) {
		if(j + 1 <= n && b[j] < b[j + 1]) ++j;
		if(b[j] > b[i]) {
			swap(b[i], b[j]);
			i = j;
			j *= 2;
		} else break;
	}

}
int main() {
	memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	int ind = 2, pos;
	while(ind <= n && b[ind - 1] <= b[ind]) ind++; //前面 min->max
	pos = ind;
	while(ind <= n && a[ind] == b[ind]) ind++; //后面 a[] = b[]
	//说明是插入排序
	if(ind == n + 1) {
		cout << "Insertion Sort" << endl;
		sort(b + 1, b + pos + 1);
	} else {
		cout << "Heap Sort" << endl;
		ind = n;
		while(ind > 1 && b[ind - 1] <= b[ind]) ind--;
		swap(b[1], b[ind]);
		downJust(1, ind - 1);
	}
	for(int i = 1; i <= n; i++) {
		cout << b[i];
		if(i != n) {
			cout << " ";
		} else cout << endl;
	}

	return 0;
}
