#include <bits/stdc++.h>
using namespace std;
int n;
string s[101];
int main(){
	int len = 0x3f3f3f3f; 
	cin >> n;
	getchar();
	for(int i = 0; i < n; i++){
		getline(cin, s[i]);
		reverse(s[i].begin(), s[i].end());
		len = min(len, int(s[i].length()));
	}
//	cout << len << endl;
	string ans = "";
	for(int i = 0; i < len; i++){
		int flag = 0;
		for(int j = 1; j < n; j++){
			if(s[j][i] != s[0][i]){
				flag = 1;break;
			}
		}
		if(flag){
			break;
		}else {
			ans += s[0][i];
		}
	}
	reverse(ans.begin(), ans.end());
	if(ans.size() == 0){
		cout << "nai" << endl;
	}else 
		cout << ans << endl;
	return 0;
}
