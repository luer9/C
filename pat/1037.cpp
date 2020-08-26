//正数与正数相乘 负数与负数相乘 
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int Nc, Np;
ll cs, ps;
vector<ll> cous;
vector<ll> pros;

int cmp(ll a, ll b) {
	return a > b;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> Nc;
	for(int i = 0; i < Nc; i++){
		cin >> cs;
		cous.push_back(cs);
	}
	cin >> Np;
	for(int i = 0; i < Np; i++){
		cin >> ps;
		pros.push_back(ps);
	}
	sort(cous.begin(), cous.begin()+Nc);
	sort(pros.begin(), pros.begin()+Np);
	ll ans = 0;
	for(int i = 0; i < Nc && i < Np; i++){
		if(cous[i] < 0 && pros[i] < 0){
			ans += cous[i] * pros[i];
		} else break;
	}
	for(int i = Nc - 1, j = Np - 1; i >= 0 && j >= 0; i--, j--){
		if(cous[i] > 0 && pros[j] > 0){
			ans += cous[i] * pros[j];
		}else break;
	}
	cout << ans << endl;
	return 0;
}
/*
4 2 1 -1   max -> min
7 6 -2 -3   max -> min
28+12+3 = 43
*/
