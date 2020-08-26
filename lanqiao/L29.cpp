#include <bits/stdc++.h>
using namespace std;
string An(int n){
	int i = 0;
	string A;
	A.append("sin(");
	string num;
	for(i = 1; i < n; i++){
		num = i + '0';
		if(i % 2 != 0){
			A.append(num + "-sin(");
		}else {
			A.append(num + "+sin(");
		}
	}
	num = i + '0';
	A.append(num);
	for(int i = 1; i <= n; i++){
		A.append(")");	
	} 
	return A; 
}
string Sn(int n){
	int i = 0;
	string num, num1, s;
	for(int i = 1; i < n; i++){
		s.append("(");
	}
	for(int i = n; i > 1; i--) {
		num1 = n - i + 1 + '0';
		num = i + '0';
		s.append(An(n - i + 1) + "+" + num +")");
	}
	s.append(An(n)+"+1");
	return s;
}
int main(){
	int n;
	cin >> n;
	cout << Sn(n);
	return 0;
}
