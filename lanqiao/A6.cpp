#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int cnt = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> a >> b >> c;
	for(int i = 1; i <= n; i++){
		if(i % a != 0 && i % b != 0 && i % c != 0){
			cnt ++;
		}
	}
	cout << cnt << endl;
	return 0;
}
