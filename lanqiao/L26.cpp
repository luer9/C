#include<bits/stdc++.h>
using namespace std;

int main(){
	double a1, b1, a2, b2;
	double A1, B1, A2, B2;
	cin >> a1 >> b1 >> a2 >> b2;
	cin >> A1 >> B1 >> A2 >> B2;
	double a, b, A, B; 
	//»­Í¼Àí½â 
	a = max(min(a1, a2), min(A1, A2));
	b = max(min(b1, b2), min(B1, B2));
	A = min(max(a1, a2), max(A1, A2));
	B = min(max(b1, b2), max(B1, B2));
	if(A > a && B > b) {
		cout << fixed << setprecision(2) << (A - a)*(B- b) << endl;
	}else{
		cout << "0.00" << endl;
	}
	return 0;
} 
