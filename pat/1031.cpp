/*

n1 + n2 + n3 = N + 2; ?n1 和 n3相等，2 * n1 + n2 = N + 2; 
要找出满足条件的最大的n1，即三边之和尽可能的满足均分。
多的给底边n2。正好在c/c++中的除法运算会舍弃小数部分。
n1 = (N + 2)/3，底边 n2 = (N+2) - 2 * n1;

*/
#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int i,j,n1,n2,l;
	string s;
	cin>>s;
	l = s.length();
	n1 = (l + 2) / 3;
	n2 = l + 2 - 2 * n1;
	for(i = 1; i < n1; i++){
		cout<<s[i-1];
		for(j = 1; j <= n2 - 2; j++) cout<<" ";
		cout<<s[l-i]<<endl;
	} 
	for(;i < n1+n2; i++) cout<<s[i-1];
	return 0;
} 