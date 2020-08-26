#include<bits/stdc++.h>
using namespace std;
int n;
int num1, num2, num;
string z;
int main(){

//	cout << 2333%(23*33) << endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> z;
		int len = z.length();
		num1 = 0; num2 = 0, num = 0; 
		for(int i = 0; i < len/2; i++){
			num1 = num1*10 + (z[i]-'0');
			num = num*10 + (z[i] - '0');
		}
		for(int i = len/2; i < len; i++){
			num2 = num2*10 + (z[i]-'0');
			num = num*10 + (z[i] - '0'); 
		}
//		cout << num1 << " " << num2 << endl;
		 if(num < num1*num2 || (num%(num1*num2) != 0) || num1 ==0 || num2 == 0) {
		 	cout << "No" << endl;
		 }else if(num%(num1*num2) == 0){
		 	cout << "Yes" << endl; 
		 }
	}
	return 0;
} 
