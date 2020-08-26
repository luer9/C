#include <bits/stdc++.h>
using namespace std;
string s;
int k;
void bigNumAdd(string temp){
	int len = temp.length(), c = 0; //½øÎ» 
	for(int i = len - 1; i >= 0; i--){
		s[i] = (s[i] - '0') + (temp[i] - '0') + c + '0';
//		cout << "----" << s[i] << endl;
		c = 0;
		if(s[i] > '9'){
			s[i] = s[i] - '0' - 10 + '0';
			c = 1;
		} 
	}
	if(c) s = '1' + s;
}
int main(){
	int i;
	string temp;
	cin >> s >> k;
	for(i = 0; i <= k; i++){
		temp = s;
		reverse(temp.begin(), temp.end());
		if(temp == s || i == k) break;
		bigNumAdd(temp); 
	}
	cout << s << endl << i << endl;
	return 0;
} 
