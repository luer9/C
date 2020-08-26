#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
void f(ll t, ll a, ll b) {
	if (b == 0) {
		printf("Inf");
		return;
	}else if (b < 0) {
		a = -a;
		b = -b;
	}

	if (abs(a) >= b) {
		t = a / b;
		a = abs(a % b);
	}
	ll k = gcd(abs(a), b);//  0/0
	a /= k, b /= k;

	if (t > 0) {
		printf("%lld", t);
		if (a) {
			printf(" %lld/%lld", a, b);
		}
	}
	else if (t < 0) {
		if (a) {
			printf("(%lld %lld/%lld)", t, a, b);
		}
		else {
			printf("(%lld)", t);
		}
	}
	else {
		if (a>0) {
			printf("%lld/%lld", a, b);
		}
		else if (a < 0) {
			printf("(%lld/%lld)", a, b);
		}
		else {
			printf("0");
		}
	}
}
int main() {
	ll a1, b1, a2, b2, t1 = 0, t2 = 0;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	f(t1, a1, b1); printf(" + "); f(t2, a2, b2); printf(" = "); f(0, a1 * b2 + a2 * b1, b1 * b2); printf("\n");
	f(t1, a1, b1); printf(" - "); f(t2, a2, b2); printf(" = "); f(0, a1 * b2 - a2 * b1, b1 * b2); printf("\n");
	f(t1, a1, b1); printf(" * "); f(t2, a2, b2); printf(" = "); f(0, a1 * a2, b1 * b2); printf("\n");
	f(t1, a1, b1); printf(" / "); f(t2, a2, b2); printf(" = "); f(0, a1 * b2, b1 * a2); printf("\n");
	return 0;
}

