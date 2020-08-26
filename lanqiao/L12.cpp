#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, h, m, s;
	cin >> t;
	h = t / 3600;
	m = t / 60 - h * 60;
	s = t % 60;
	cout << h << ":" << m << ":" << s << endl;
	return 0;
}
