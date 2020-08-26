#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n1, n2;
ll a;
//priority_queue<ll> q;
vector<ll> vec;
int main(){
	ios::sync_with_stdio(false);
	cin >> n1;
	for(int i = 0; i < n1; i++){
		cin >> a;
//		q.push(a);
		vec.push_back(a);	
	}
	cin >> n2;
	for(int i = 0; i < n2; i++){
		cin >> a;
//		q.push(a);
		vec.push_back(a);
	} 
	sort(vec.begin(), vec.end());
	
	int mid = (n1 + n2 - 1) / 2;
	vector<ll> ::iterator it;
	it = vec.begin() + mid;
	cout <<(*it) << endl;
//	int ind = 0;
//	while(!q.empty()){
//		
//		ind ++;
//		if(ind == mid){
//			cout << q.top() << endl;
//			break;
//		} 
//		q.pop();
//	}
	return 0;
}
