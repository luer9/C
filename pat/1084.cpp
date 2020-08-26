#include <bits/stdc++.h>
using namespace std;
map<char, int> mapp, vis;
string s;
string temp;

int main(){
	cin >> s >> temp;
	int lens = s.length(),lent = temp.length(); 
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
	mapp.clear(); vis.clear();
	for(int i = 0; i < lent; i++){
		mapp[temp[i]] ++;
	}
	for(int i = 0; i < lens; i++){
		if(mapp[s[i]] == 0 &&!vis[s[i]]) {
			cout << s[i];
			vis[s[i]] = 1;
		}else {
			mapp[s[i]]--;
		}
	}
	
	return 0;
} 
