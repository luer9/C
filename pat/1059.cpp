#include <bits/stdc++.h>
#define ll long long
#define Max 1110000
using namespace std;
map<ll,int> cnt; //primeµÄ´ÎÊý
bool isprime[Max];
int prime[Max];
ll a; 
int isPrime(ll a){
	if(a == 1) return 0;
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0) return 0;
	}
	return 1;
}
void getPrime(){
	int ind = 0;
	memset(isprime, true, sizeof(isprime));
	for(int i = 2; i <= 1000000; i++){
		if(isprime[i]){
			prime[ind++] = i;
		}
		for(int j = 0; j < ind && prime[j] * i <= 1000000; j++){
			isprime[prime[j] * i] = false;
			if(i % prime[j] == 0) {
				break;
			}
		}
	}
}
int main(){
	set<ll> s;
	s.clear(); cnt.clear();
	getPrime();
	cin >> a;
	if(isPrime(a)) {
		cout << a << "=" << a << endl;
	}else{
		cout << a << "=";
		int ind = 0;
		ll temp = a;
		while(true){
			if(temp % prime[ind] == 0) {
				temp /= prime[ind];
				s.insert(prime[ind]);
				cnt[prime[ind]]++;
			}else {
				ind++;
			}
			if(temp == 1) break;
		}
		if(a == 1) {
			s.insert(1);
			cnt[1]++;	
		} 
		int num = s.size();
//		cout << "--->: " << num << endl;
		set<ll>::iterator it;
		for(it = s.begin(); it != s.end(); it++){
			if(cnt[(*it)] >= 2) {
				cout << (*it) << "^" << cnt[(*it)];
			}else {
				cout << (*it);
			}
			num --;
			if(num != 0) cout << "*";
		}
		cout << endl;
	}
	return 0;
} 
