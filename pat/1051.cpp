#include <bits/stdc++.h>
using namespace std;
int m, n, k;

int main(){
	cin >> m >> n >> k;
	for(int i = 0; i < k; i++){
		vector <int> v(n);
		int flag = 1;
		for(int j = 0; j < n; j++){
			cin >> v[j];
		}
		stack<int> s; while(!s.empty()) s.pop();
		int ind = 0;
		for(int j = 1; j <= n; j++){
			s.push(j);
			if(s.size() > m){
				flag = 0;
				break;
			}
			while(!s.empty() && s.top() == v[ind]){
				s.pop();
				ind++;
			}
		}
		if(!s.empty()) flag = 0;
		cout << ((flag == 1) ? "YES": "NO") << endl;
	}
	
	return 0;
} 
