#include <bits/stdc++.h>
using namespace std;
char s[10] = "LANQIAO";
//7 ��  A����һ����  6 �� 
int main(){
	set<string> se;
	se.clear();
	do{
		cout << s << endl;
		se.insert(s);
	}while(next_permutation(s,s+7));
	cout << se.size() << endl;
	return 0;
}
