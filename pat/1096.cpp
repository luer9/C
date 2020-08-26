#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isPrime(ll a){
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0) return false;
	}
	return true;
}
int main(){
	ll n;
	cin >> n;
	if(isPrime(n)){
		cout << "1" << endl << n << endl;
	}else {
		int maxx = -1, j, ind;
		for(int i = 2; i <= sqrt(n); i++){
			ll sum = 1;
			for(j = 0; ; j++){
				sum *= (i+j);
//				cout << "---> " << sum << endl;
				if(n % sum != 0) break;
			}
			if(j > maxx) {
				maxx = j;
				ind = i;
			}
		}
		cout << maxx << endl;
		cout << ind;
		for(int i = 1; i < maxx; i++){
			cout << "*" << ind+i;
		}
		cout << endl;
	}
	return 0;
} 
