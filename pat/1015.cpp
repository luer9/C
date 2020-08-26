#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, d;
ll change(int a,int d) {
	int b[1002], index = 0;
	while(a) {
		int c = a % d;
		b[index++] = c;
		a /= d;
	} 
	ll sum = 0;
	for(int i = 0; i < index; i++) {
//		cout <<"-->: "<< b[i] << endl;
		sum = sum * d + b[i];
	}
	return sum;
}
//ll traverse(ll a) {
//	ll sum = 0;
//	while(a) {
//		int c = a % 10;
//		sum = sum * 10 + c;
//		a /= 10;
//	} 
//	return sum;
//}
int isprime(ll a) {
	if (a == 1 || a == 0) return 0;
	for(int i = 2; i <= sqrt(a); i++) {
		if(a % i == 0) {
			return 0;
		}
	} 
	return 1;
}

int main() {
	while (cin >> n) {
		if (n < 0) break;
		cin >> d;
		ll a = change(n, d); // 在d进制下的 n 
//		cout << "-- > " << a << endl; 
		if(isprime(a) && isprime(n)) {
			cout << "Yes" << endl;
		}else cout << "No" << endl;
	}
	return 0;
}
