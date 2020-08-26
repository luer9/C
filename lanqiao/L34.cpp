#include <bits/stdc++.h>
using namespace std;
int check(int a){
	if(a%10 == 9 || a/10%10 == 9 || a/100%10 == 9 || a/1000%10 == 9){
		return 1;
	}
	return 0;
}
int main(){
	int cnt = 0;
	for(int i = 1; i <= 2019; i++){
		if(check(i)){
			cnt++;
			cout <<"-----> "<< i << "  " << cnt <<endl;
		}
	}
	cout <<cnt<< endl;
	return 0;
}
