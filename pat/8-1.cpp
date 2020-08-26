#include <bits/stdc++.h>
using namespace std;
int isprime(int a){
	if(a == 1 || a == 0) return 0;
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0)
			return 0;
	}
	return 1;
}
int sti(string s){
	int len = s.length();
	int num = 0;
	for(int i = 0; i < len; i++){
		num = num * 10 + (s[i]-'0');
	}
	return num;
}
int main(){
	string s, temp = "";
	int len = 0, flag = 0;
	cin >> s;
	len = s.length();
	for(int i = 0; i < len; i++){
		temp = s.substr(i,len);
	
		cout << temp << " ";
		if(isprime(sti(temp))){
			cout << "Yes" << endl;
		}else {
			flag = 1;
			cout << "No" << endl;
		}
	}
	if(!flag){
		cout << "All Prime!" << endl;
	}
	
	return 0;
}
