#include <bits/stdc++.h>
using namespace std;
int n, k;
//A student name consists of 3 capital English letters plus a one-digit number.
int hashId(string name){
	int id = 0;
	for(int i = 0; i < 3; i++){
		id = 26 * id + (name[i] - 'A');
	}
	id += id * 10 + (name[3] - '0');
	return id;
}
int main(){
	ios::sync_with_stdio(false);
	int Ki, Ni;
	string name;
	map<int, set<int> > mapp;
	set<int>::iterator sit;
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> Ki >> Ni;
		for(int j = 0; j < Ni; j++){
			cin >> name;
			mapp[hashId(name)].insert(Ki); 
		}
	}
	int hashCode;
	for(int i = 0; i < n; i++){
		cin >> name; hashCode = hashId(name);
		cout << name << " " << mapp[hashCode].size();
	
		for(sit = mapp[hashCode].begin(); sit != mapp[hashCode].end(); sit++){
			cout << " " << (*sit);
		}
		cout << endl;
	}
	return 0;
}
