#include <bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int a,int b) {
	return b == 0 ? a : gcd(b, a%b);
}
int main() {
	ll a1, b1, a2, b2, n;
	scanf("%lld",&n);
	scanf("%lld/%lld",&a1,&b1);
	int c = gcd(a1, b1);
	a1 = a1 / c;
	b1 = b1 / c;
	for(int i = 1; i < n; i++) {
		scanf("%lld/%lld",&a2,&b2);
		a1 = a1 * b2 + a2 * b1;
		b1 = b1 * b2;
		int c = gcd(a1, b1);
		a1 = a1 / c;
		b1 = b1 / c;

	}
	if(b1 == 0 || a1 == 0) {
		printf("0"); //最后的一个坑点 分子为0 输出0 
	}else {
		if(a1 >= b1) {
		if(a1 % b1 == 0 ) {
			printf("%lld", a1/b1);
		} else if(a1 % b1 != 0) {
			printf("%lld ", a1/b1);
			a1 = a1 % b1;
			printf("%lld/%lld",a1, b1);
		}
	} else {

		printf("%lld/%lld",a1, b1);
	}

	}
	
	return 0;
}
