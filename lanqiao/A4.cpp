#include <bits/stdc++.h>
using namespace std;
int main(){
	char s[101];
	cin >> s;
	for(int i = 0; i < strlen(s); i++){
		if(s[i]>='a' && s[i] <='w'){
			cout << char(s[i] + 3);
		}else if(s[i] == 'x'){
			cout << 'a';
		}else if(s[i] == 'y'){
			cout << 'b';
		}else if(s[i] == 'z'){
			cout << 'c';
		} 
	}
	cout << endl;
	return 0;
} 
