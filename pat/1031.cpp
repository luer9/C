/*

n1 + n2 + n3 = N + 2; ?n1 �� n3��ȣ�2 * n1 + n2 = N + 2; 
Ҫ�ҳ���������������n1��������֮�;����ܵ�������֡�
��ĸ��ױ�n2��������c/c++�еĳ������������С�����֡�
n1 = (N + 2)/3���ױ� n2 = (N+2) - 2 * n1;

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