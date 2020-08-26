#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n, len;
	cin >> s >> n;

	for(int k = 1; k < n; k++){
		len = s.length();
		string temp = "";
		int cnt = 0;
		char pre = s[0];
//		cout << "len: " << len << "  ---> " << pre << endl;
		for(int i = 0; i < len; i++){
			if(s[i] == pre) cnt++;
			else {
				temp += pre;
				temp += cnt + '0';
				pre = s[i];
				cnt = 1;
			}
		}
		if(cnt >= 1){
			temp += pre;
			temp += cnt + '0';
		}
		s = temp;
	}
	cout << s << endl; 
	return 0;
} 
