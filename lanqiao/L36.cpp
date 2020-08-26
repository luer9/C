#include <iostream>
#include <cstring>
#define Max 1000005 
using namespace std;
int n;
int p[Max]; //记录在第i个数时有多少个数是递增的
int judge(int a){
	int num[11] = {0}, index = 0;
	while(a){
		int c = a % 10;
		num[index++] = c;
		a /= 10;
	}
//	if(index == 1) return 0;
	for(int i = index - 1; i >= 1; i--){
		if(num[i] > num[i-1]){
			return 0;
		}
	}
	return 1;
}
void init(){
	memset(p, 0, sizeof(p));
	for(int i = 1; i <= 1000000; i++){
		if(judge(i)){
			p[i] = p[i-1] + 1;
		}else p[i] = p[i-1];
	}
} 

int main(){
	init();
	cin >> n;
	cout << p[n] << endl;
	return 0;
}
