#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
ll a, b, c;
int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("in.txt","r",stdin);
#endif 
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> a >> b >> c;
		cout << "Case #"<< i <<": ";
//		cout << "---->" << c - a << endl;
		if(b > (c - a)){
			cout << "true" << endl; 
		} else{
			cout << "false" << endl; 
		}
	}
	return 0;
} 
