#include <bits/stdc++.h>
#define Max 111110
using namespace std;
struct Node{
	int nex;
	char data;//
	int flag;
}node[Max];
int s1, s2, n; 
int ad, nexx;
char d;
int main(){
	
	cin >> s1 >> s2 >> n;
	for(int i = 0; i < n; i++){
		cin >> ad >> d >> nexx;
		node[ad].data = d;
		node[ad].nex = nexx;
		node[ad].flag = 0; 
	}
	for(int i = s1; i != -1; i = node[i].nex){
		node[i].flag = 1;
	}
	for(int i = s2; i != -1; i = node[i].nex){
		if(node[i].flag == 1){
			printf("%05d", i);
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}
//L O A D I N G
//B E I N G
