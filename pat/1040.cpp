#include <bits/stdc++.h>
using namespace std;
string s, temp;
int main(){
	getline(cin, s);
	int len = s.length(), maxx = -1;
	for(int i = 0; i < len; i++){
		for(int j = 1; j <= len - i; j++){
			temp = s.substr(i, j);
			string s1 = temp;
			int len1 = s1.length();
			reverse(temp.begin(), temp.end());
//			cout << "---->" << s1 <<" --- "<< temp << "---"<< (s1 == temp) << endl;
		
			if(s1 == temp && maxx < len1){
//				cout << "***" << len1 << endl;
				maxx = len1;
			}
		}
	}
	cout << maxx << endl;
	return 0;
}
