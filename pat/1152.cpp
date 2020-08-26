#include <bits/stdc++.h>
#define ll long long
using namespace std;
int L, K;
string s;
int isprime(ll a){
	if( a == 1) return 0;
	for(int i = 2;  i <= sqrt(a); i++){
		if(a % i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	cin >> L >> K;
	cin >> s;
	int len = s.length();
//	int flag = 0;
	for(int i = 0; i <= len - K; i++){
		ll num = 0;
		for(int j = i; j < i+K; j++){
			num = num*10 + (s[j] - '0');
		}
		if(isprime(num)){
//			flag = 1;
			cout << s.substr(i,K) << endl;  //因为前导的0也不能省 所以要输出 string 类型 
			return 0;
		}
	}
//	if(!flag) {
		cout << "404"<< endl;
//	}
	return 0;
}
