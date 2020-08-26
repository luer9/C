#include <bits/stdc++.h>
using namespace std;
map<string, int> mapp;
map<string, int> vis;
int n, k;
string s;
bool isprime(int a){
	if(a == 0) return false;
	if(a == 1) return true;//ÊÇËØÊı
	for(int i = 2; i <= sqrt(a); i++) {
		if(a % i == 0){
			return false;
		}
	} 
	return true;
}
int main(){
	mapp.clear();
	vis.clear();
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		mapp[s] = i;
	}
	cin >> k;
	for(int i = 0; i < k; i++) {
		cin >> s;
		if(!vis[s]){
			if(mapp[s] == 1) {
			cout << s << ": Mystery Award" << endl;
			vis[s] = 1;
			}else if(isprime(mapp[s])){
				cout << s << ": Minion" << endl;vis[s] = 1;
			}else if(mapp[s] != 0) {
				cout << s << ": Chocolate" << endl;vis[s] = 1;
			}else{
				cout << s << ": Are you kidding?" << endl;
			}
			
		}else{
			cout << s << ": Checked" << endl;			
		}
	}
	
	return 0;
}
