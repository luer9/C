//分数的加减乘除
/*
如果分母为 0 result输出 inf
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a1, a2, b1, b2;
ll gcd(ll a, ll b) {
	while(b) {
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}
ll lcm(ll a, ll b) {
	return a*b/gcd(a,b);
}
void display(ll a1, ll b1) {
	if(a1 == 0 || b1 == 0) {
		cout << "0";
	} else {
		if(abs(a1) < abs(b1)) {
			if(a1 < 0) cout << "(";
			cout << a1 << "/" << b1;
			if(a1 < 0) cout << ")";
		}
		if(abs(a1) >= abs(b1)) {
			int flag = 0;
			ll temp1 = a1 / b1; // 整数
			ll temp2 = a1 % b1; //分子
			if(temp1 < 0) {
				flag = 1;
				cout << "(";
				cout << temp1;
			} else cout << temp1;
			if(temp2 != 0) {
				cout << " " << abs(temp2) << "/" << b1;
			}
			if(flag) cout << ")";
		}
	}

}
//把结果算出来先
int main() {
	scanf("%lld/%lld %lld/%lld",&a1, &a2, &b1, &b2);

	ll resfenzi = a1 * lcm(a2, b2) / a2 + b1 * lcm(a2, b2) / b2;
	ll resfenmu = lcm(a2, b2);
	ll gcdd = gcd(resfenzi, resfenmu);
	resfenzi = resfenzi / gcdd ;
	resfenmu = resfenmu / gcdd ;
	display(a1, a2);
	//加
	cout << " + ";
	display(b1, b2);
	cout << " = ";
	if(resfenmu < 0) {
		resfenmu = -resfenmu;
		resfenzi = -resfenzi;
	}
	display(resfenzi, resfenmu);
	cout << endl;
	//减
	display(a1, a2);
	cout << " - ";
	display(b1, b2);
	cout << " = ";
	resfenzi = a1 * lcm(a2, b2) / a2 - b1 * lcm(a2, b2) / b2;
	resfenmu = lcm(a2, b2);
	gcdd = gcd(resfenzi, resfenmu);
	resfenzi = resfenzi / gcdd ;
	resfenmu = resfenmu / gcdd ;
	if(resfenmu < 0) {
		resfenmu = -resfenmu;
		resfenzi = -resfenzi;
	}
	display(resfenzi, resfenmu);
	cout << endl;
	//乘
	display(a1, a2);
	cout << " * ";
	display(b1, b2);
	cout << " = ";
	resfenzi = a1 * b1;
	resfenmu = a2 * b2;
	gcdd = gcd(resfenzi, resfenmu);
	resfenzi = resfenzi / abs(gcdd) ;
	resfenmu = resfenmu / abs(gcdd) ;
	if(resfenmu < 0) {
		resfenmu = -resfenmu;
		resfenzi = -resfenzi;
	}
	display(resfenzi, resfenmu);
	cout << endl;
	//除
	display(a1, a2);
	cout << " / ";
	display(b1, b2);
	cout << " = ";
	resfenzi = a1 * b2;
	resfenmu = a2 * b1;
	if(resfenmu == 0) cout << "Inf" << endl;
	else {
		gcdd = gcd(resfenzi, resfenmu);
		resfenzi = resfenzi / abs(gcdd) ;
		resfenmu = resfenmu / abs(gcdd) ;
		if(resfenmu < 0) {
			resfenmu = -resfenmu;
			resfenzi = -resfenzi;
		}
		display(resfenzi, resfenmu);
	}


	
	return 0;
}


