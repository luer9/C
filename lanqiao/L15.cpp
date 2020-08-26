#include <bits/stdc++.h>
using namespace std;
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 != len2) {
		cout << "1" << endl;
	}else {
		if(s1 == s2) {
			cout << "2" << endl;
		}else if(s1 != s2) {
			transform(s1.begin(),s1.end(),s1.begin(),::toupper);
			transform(s2.begin(),s2.end(),s2.begin(),::toupper);
			if(s1 == s2) {
				cout << "3" << endl;
			}else{
				cout << "4" << endl;
			}
		}
	}
	return 0;
}
