#include <bits/stdc++.h>
using namespace std;
int main(){
	
	string s;
	cin >> s;
	int len = s.length();
	for(int i = 0; i < len; i++){
		if(s[i] >='a' && s[i] <='z'){
			cout << char(s[i]- 'a' + 'A');
		}
		else if(s[i] >= 'A' && s[i] <= 'Z'){
			cout << char(s[i] - 'A' + 'a'); 
		}
	}
	return 0;
} 
