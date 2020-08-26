#include <iostream>
#include <cstring>
#include <string> 
#define ll long long
#define Max 1100
using namespace std;
ll f[Max];
int n;
void init(){
	memset(f, 0, sizeof(f));
	f[1] = 1; 
	int index = 1;
	for(int i = 2; i <= 1000; i++){
		f[i] = (f[i-1] + index)%10000;
		index ++;
	}
}
int main(){
	init();
	cin >> n;
	cout << f[n] << endl; 
//	for(int i = 1; i <= 1000; i++) {
//		cout << i <<" : "<< f[i] << endl;
//	}
	return 0;
}

/*
1£º1
2: 2
3£º4
4£º7
5: 11
6: 16
Ïà²î 1 2 3 4 5 
*/




